#include "Base.h"
#include "DepthStencilTarget.h"

#ifndef GL_DEPTH24_STENCIL8_OES
#define GL_DEPTH24_STENCIL8_OES 0x88F0
#endif
#ifndef GL_DEPTH_COMPONENT24
#define GL_DEPTH_COMPONENT24 GL_DEPTH_COMPONENT24_OES
#endif

namespace gameplay
{

static std::vector<DepthStencilTarget*> __depthStencilTargets;

DepthStencilTarget::DepthStencilTarget(const char* id, Format format, unsigned int width, unsigned int height)
    : _id(id ? id : ""), _format(format), _depthBuffer(0), _stencilBuffer(0), _width(width), _height(height), _packed(false)
{
}

DepthStencilTarget::~DepthStencilTarget()
{
    // Destroy GL resources.
    if (_depthBuffer)
        GPRHI_ASSERT( GPRHI_DeleteRenderbuffers(1, &_depthBuffer) );
    if (_stencilBuffer)
        GPRHI_ASSERT( GPRHI_DeleteRenderbuffers(1, &_stencilBuffer) );

    // Remove from vector.
    std::vector<DepthStencilTarget*>::iterator it = std::find(__depthStencilTargets.begin(), __depthStencilTargets.end(), this);
    if (it != __depthStencilTargets.end())
    {
        __depthStencilTargets.erase(it);
    }
}

DepthStencilTarget* DepthStencilTarget::create(const char* id, Format format, unsigned int width, unsigned int height)
{
    // Create the depth stencil target.
    DepthStencilTarget* depthStencilTarget = new DepthStencilTarget(id, format, width, height);

    // Create a render buffer for this new depth+stencil target
    GPRHI_ASSERT( GPRHI_GenRenderbuffers(1, &depthStencilTarget->_depthBuffer) );
    GPRHI_ASSERT( GPRHI_BindRenderbuffer(GP_RHI_BUFFER_RENDER_BUFFER, depthStencilTarget->_depthBuffer) );

    // First try to add storage for the most common standard GP_RHI_FORMAT_D24S8 
    GPRHI_RenderbufferStorage(GP_RHI_BUFFER_RENDER_BUFFER, GP_RHI_FORMAT_D24S8, width, height);

    // Fall back to less common GLES2 extension combination for seperate depth24 + stencil8 or depth16 + stencil8
    __gl_error_code = GPRHI_GetError();
    if ( __gl_error_code != GP_NO_ERROR)
    {
        const char* extString = (const char*)glGetString(GL_EXTENSIONS);

        if (strstr(extString, "GL_OES_packed_depth_stencil") != 0)
        {
            GPRHI_ASSERT( GPRHI_RenderbufferStorage(GP_RHI_BUFFER_RENDER_BUFFER, GL_DEPTH24_STENCIL8_OES, width, height) );
            depthStencilTarget->_packed = true;
        }
        else
        {
            if (strstr(extString, "GL_OES_depth24") != 0)
            {
                GPRHI_ASSERT( GPRHI_RenderbufferStorage(GP_RHI_BUFFER_RENDER_BUFFER, GP_RHI_FORMAT_D24F, width, height) );
            }
            else
            {
                GPRHI_ASSERT( GPRHI_RenderbufferStorage(GP_RHI_BUFFER_RENDER_BUFFER, GP_RHI_FORMAT_D16F, width, height) );
            }
            if (format == DepthStencilTarget::DEPTH_STENCIL)
            {
                GPRHI_ASSERT( GPRHI_GenRenderbuffers(1, &depthStencilTarget->_stencilBuffer) );
                GPRHI_ASSERT( GPRHI_BindRenderbuffer(GP_RHI_BUFFER_RENDER_BUFFER, depthStencilTarget->_stencilBuffer) );
                GPRHI_ASSERT( GPRHI_RenderbufferStorage(GP_RHI_BUFFER_RENDER_BUFFER, GP_RHI_FORMAT_S8, width, height) );
            }
        }
    }
    else
    {
        // Packed format GP_RHI_FORMAT_D24S8 is used mark format as packed.
        depthStencilTarget->_packed = true;
    }

    // Add it to the cache.
    __depthStencilTargets.push_back(depthStencilTarget);

    return depthStencilTarget;
}

DepthStencilTarget* DepthStencilTarget::getDepthStencilTarget(const char* id)
{
    GP_ASSERT(id);

    // Search the vector for a matching ID.
    std::vector<DepthStencilTarget*>::const_iterator it;
    for (it = __depthStencilTargets.begin(); it < __depthStencilTargets.end(); it++)
    {
        DepthStencilTarget* dst = *it;
        GP_ASSERT(dst);
        if (strcmp(id, dst->getId()) == 0)
        {
            return dst;
        }
    }
    return NULL;
}

const char* DepthStencilTarget::getId() const
{
    return _id.c_str();
}

DepthStencilTarget::Format DepthStencilTarget::getFormat() const
{
    return _format;
}

unsigned int DepthStencilTarget::getWidth() const
{
    return _width;
}

unsigned int DepthStencilTarget::getHeight() const
{
    return _height;
}

bool DepthStencilTarget::isPacked() const
{
    return _packed;
}
}
