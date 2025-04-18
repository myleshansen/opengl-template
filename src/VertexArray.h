//
// Created by Myles Hansen on 4/17/25.
//

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray {
private:
    unsigned int m_RendererID;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& ib);
    void Bind() const;
    void Unbind() const;
};



#endif //VERTEXARRAY_H
