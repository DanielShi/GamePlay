#include "Base.h"
#include "MeshPart.h"

namespace gameplay
{

MeshPart::MeshPart() :
    _mesh(NULL), _meshIndex(0), _primitiveType(Mesh::TRIANGLES), _indexCount(0), _indexBuffer(0), _dynamic(false)
{
}

MeshPart::~MeshPart()
{
    if (_indexBuffer)
    {
		GPRHI_DeleteBuffers(1, &_indexBuffer);
    }
}

MeshPart* MeshPart::create(Mesh* mesh, unsigned int meshIndex, Mesh::PrimitiveType primitiveType,
    Mesh::IndexFormat indexFormat, unsigned int indexCount, bool dynamic)
{
    // Create a VBO for our index buffer.
    GLuint vbo;
    GPRHI_ASSERT( GPRHI_GenBuffers(1, &vbo) );
    GPRHI_ASSERT( GPRHI_BindBuffer(GP_RHI_BUFFER_INDEX, vbo) );

    unsigned int indexSize = 0;
    switch (indexFormat)
    {
    case Mesh::INDEX8:
        indexSize = 1;
        break;
    case Mesh::INDEX16:
        indexSize = 2;
        break;
    case Mesh::INDEX32:
        indexSize = 4;
        break;
    default:
        GP_ERROR("Unsupported index format (%d).", indexFormat);
		GPRHI_DeleteBuffers(1, &vbo);
        return NULL;
    }

    GPRHI_ASSERT( GPRHI_BufferData(GP_RHI_BUFFER_INDEX, indexSize * indexCount, NULL, dynamic ? GP_RHI_BUFFER_DANAMIC : GP_RHI_BUFFER_STATIC) );

    MeshPart* part = new MeshPart();
    part->_mesh = mesh;
    part->_meshIndex = meshIndex;
    part->_primitiveType = primitiveType;
    part->_indexFormat = indexFormat;
    part->_indexCount = indexCount;
    part->_indexBuffer = vbo;
    part->_dynamic = dynamic;

    return part;
}

unsigned int MeshPart::getMeshIndex() const
{
    return _meshIndex;
}

Mesh::PrimitiveType MeshPart::getPrimitiveType() const
{
    return _primitiveType;
}

unsigned int MeshPart::getIndexCount() const
{
    return _indexCount;
}

Mesh::IndexFormat MeshPart::getIndexFormat() const
{
    return _indexFormat;
}

IndexBufferHandle MeshPart::getIndexBuffer() const
{
    return _indexBuffer;
}

bool MeshPart::isDynamic() const
{
    return _dynamic;
}

void MeshPart::setIndexData(const void* indexData, unsigned int indexStart, unsigned int indexCount)
{
    GPRHI_ASSERT( GPRHI_BindBuffer(GP_RHI_BUFFER_INDEX, _indexBuffer) );

    unsigned int indexSize = 0;
    switch (_indexFormat)
    {
    case Mesh::INDEX8:
        indexSize = 1;
        break;
    case Mesh::INDEX16:
        indexSize = 2;
        break;
    case Mesh::INDEX32:
        indexSize = 4;
        break;
    default:
        GP_ERROR("Unsupported index format (%d).", _indexFormat);
        return;
    }

    if (indexStart == 0 && indexCount == 0)
    {
        GPRHI_ASSERT( GPRHI_BufferData(GP_RHI_BUFFER_INDEX, indexSize * _indexCount, indexData, _dynamic ? GP_RHI_BUFFER_DANAMIC : GP_RHI_BUFFER_STATIC) );
    }
    else
    {
        if (indexCount == 0)
        {
            indexCount = _indexCount - indexStart;
        }

        GPRHI_ASSERT( GPRHI_BufferSubData(GP_RHI_BUFFER_INDEX, indexStart * indexSize, indexCount * indexSize, indexData) );
    }
}

}
