#ifndef SKYMESH_H
#define SKYMESH_H

//#include"GL/glew.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"SkyboxCamera.h"

#include<string>
#include<vector>
#include<QOpenGLExtraFunctions>
struct Vertex
{
    //position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    //texCoord
    glm::vec2 TexCoords;
    //tangent
    glm::vec3 Tangent;
    //bitangent
    glm::vec3 Bitangent;
};

struct Texture 
{
    unsigned int id ;
    std::string type;
    std::string  path;
};

class Mesh:public QOpenGLExtraFunctions
{
public :
    // mesh data
    std::vector<Vertex> vertices;
    std::vector<unsigned int > indices;
    std::vector<Texture> textures;
    unsigned int VAO;

    //constructor
    Mesh(std::vector<Vertex> vertices,
         std::vector<unsigned int> indices,
         std::vector<Texture> textures)
    {
//		//初始化opengl 函数
        initializeOpenGLFunctions();
        this->vertices = vertices;
        this->indices = indices;
        this ->textures = textures;
        //set the vertex buffers and its attribute pointers
        setupMesh();
    }
    void  Draw(Shader &shader)
    {
        // bind appropriate texture
        unsigned int diffuseNr = 1;
        unsigned int specularNr =1;
        unsigned int normalNr =1 ;
        unsigned int heightNr  = 1;

        for(unsigned int i= 0; i < textures.size() ;++ i)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            std::string number;
            std::string name = textures[i] .type;
            if(name == "texture_diffuse")
                number = std::to_string(diffuseNr++);
            else if(name == "texture_specular")
                number = std::to_string(specularNr++); // transfer unsigned int to stream
            else if(name == "texture_normal")
                number = std::to_string(normalNr++); // transfer unsigned int to stream
            else if(name == "texture_height")
                number = std::to_string(heightNr++); // transfer unsigned int to stream
            // now set the sampler to the correct texture unit
            glUniform1i(glGetUniformLocation(shader.ID,(name+number).c_str()),i);
            glBindTexture(GL_TEXTURE_2D,textures[i].id);
			
        }
        //draw mesh
        glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES,indices.size() ,GL_UNSIGNED_INT,0);
        //GLAPI void GLAPIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
        // always good practice to set everything back to defaults once configured.
        glActiveTexture(GL_TEXTURE0);
    }
private:
    void  setupMesh()
    {
        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&VBO);
        glGenBuffers(1,&EBO);

        glBindVertexArray(VAO);
        //load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER,VBO);

        glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(Vertex),
                     &vertices[0],GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof (unsigned int),
                     &indices[0],GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3, GL_FLOAT , GL_FALSE , sizeof (Vertex),(void *)0);

        // vertex normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
        // vertex texture coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
        // vertex tangent
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
        // vertex bitangent
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

        glBindVertexArray(0);

    }
private:
    //render data
    unsigned  int VBO,EBO;

};

#endif // SKYMESH_H




