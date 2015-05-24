#ifdef HAKO_BUILD_GFXOPENGL


#ifdef HAKO_BUILD_LINUX


#ifndef HAKO_OPENGL_INCLUDES_LINUX_H
#define HAKO_OPENGL_INCLUDES_LINUX_H


#include <GL/glx.h>
#include <GL/gl.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


namespace Hako
{
	namespace OpenGL
	{
		void  linux_load_extensions ();
	}
}


typedef char GLchar;

typedef void(APIENTRY *PTR_GLGENBUFFERS)(GLsizei, GLuint*);
typedef void(APIENTRY *PTR_GLBINDBUFFER)(GLenum, GLuint);
typedef void(APIENTRY *PTR_GLBUFFERDATA)(GLenum, GLsizei, const GLvoid*, GLenum);
typedef void(APIENTRY *PTR_GLBUFFERSUBDATA)(GLenum, GLint, GLsizei, const GLvoid*);
typedef void(APIENTRY *PTR_GLDRAWRANGEELEMENTS)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid*);
typedef void(APIENTRY *PTR_GLSHADERSOURCE)(GLuint, GLsizei, char**, GLint*);
typedef void(APIENTRY *PTR_GLCOMPILESHADER)(GLuint);
typedef GLuint(APIENTRY *PTR_GLCREATEPROGRAM)();
typedef void(APIENTRY *PTR_GLATTACHSHADER)(GLuint, GLuint);
typedef void(APIENTRY *PTR_GLLINKPROGRAM)(GLuint);
typedef void(APIENTRY *PTR_GLUSEPROGRAM)(GLuint);
typedef void(APIENTRY *PTR_GLGETSHADER)(GLuint, GLenum, GLint*);
typedef GLuint(APIENTRY *PTR_GLCREATESHADER)(GLenum);
typedef void (APIENTRY *PTR_GLGETSHADERINFOLOG)(GLuint, GLsizei, GLsizei*, char*);
typedef void (APIENTRY *PTR_GLGENFRAMEBUFFERS)(GLsizei, GLuint*);
typedef void (APIENTRY *PTR_GLBINDFRAMEBUFFER)(GLenum, GLuint);
typedef void (APIENTRY *PTR_GLDELETEFRAMEBUFFERS)(GLsizei, GLuint*);
typedef void (APIENTRY *PTR_GLRENDERBUFFERSTORAGE)(GLenum, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY *PTR_GLFRAMEBUFFERRENDERBUFFER)(GLenum, GLenum, GLenum, GLuint);
typedef void (APIENTRY *PTR_GLDELETERENDERBUFFERS)(GLsizei, GLuint*);
typedef void (APIENTRY *PTR_GLFRAMEBUFFERPARAMETERI)(GLenum, GLenum, GLint);
typedef void (APIENTRY *PTR_GLFRAMEBUFFERTEXTURE)(GLenum, GLenum, GLuint, GLint);
typedef void (APIENTRY *PTR_GLFRAMEBUFFERTEXTURE1D)(GLenum, GLenum, GLenum, GLuint, GLint);
typedef void (APIENTRY *PTR_GLFRAMEBUFFERTEXTURE2D)(GLenum, GLenum, GLenum, GLuint, GLint);
typedef void (APIENTRY *PTR_GLFRAMEBUFFERTEXTURE3D)(GLenum, GLenum, GLenum, GLuint, GLint, GLint);
typedef GLenum(APIENTRY *PTR_GLCHECKFRAMEBUFFERSTATUS)(GLenum);
typedef void (APIENTRY *PTR_GLDRAWBUFFERS)(GLsizei, const GLenum*);
typedef void (APIENTRY *PTR_GLACTIVETEXTURE)(GLenum);
typedef GLint(APIENTRY *PTR_GLGETUNIFORMLOCATION)(GLuint, const GLchar*);
typedef void (APIENTRY *PTR_GLUNIFORM1I)(GLint, GLint);
typedef void (APIENTRY *PTR_GLUNIFORM1F)(GLint, GLfloat);
typedef void (APIENTRY *PTR_GLUNIFORM2F)(GLint, GLfloat, GLfloat);
typedef void (APIENTRY *PTR_GLUNIFORM3F)(GLint, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PTR_GLUNIFORM4F)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PTR_GLCLEARBUFFERFV)(GLenum, GLint, const GLfloat*);
typedef GLint(APIENTRY *PTR_GLUNIFORMMATRIX4FV)(GLint, GLsizei, GLboolean, GLfloat*);
typedef void (APIENTRY *PTR_GLVERTEXATTRIBPOINTER)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);
typedef void(APIENTRY* PTR_GLENABLEVERTEXATTRIBARRAY)(GLuint);
typedef void(APIENTRY* PTR_GLDISABLEVERTEXATTRIBARRAY)(GLuint);
typedef void(APIENTRY* PTR_GLGENVERTEXARRAYS)(GLsizei, GLuint*);
typedef void(APIENTRY* PTR_GLDELETEVERTEXARRAYS)(GLsizei, const GLuint*);
typedef void(APIENTRY* PTR_GLBINDVERTEXARRAY)(GLuint);
typedef GLint(APIENTRY* PTR_GLGETATTRIBLOCATION)(GLuint, const GLchar*);
typedef void(APIENTRY* PTR_GLBINDFRAGDATALOCATION)(GLuint, GLuint, const char*);
typedef const char*(APIENTRY* PTR_GLGETSTRINGI)(GLenum, GLint);

extern PTR_GLBINDFRAGDATALOCATION glBindFragDataLocation;
extern PTR_GLGETATTRIBLOCATION glGetAttribLocation;
extern PTR_GLGENVERTEXARRAYS glGenVertexArrays;
extern PTR_GLDELETEVERTEXARRAYS glDeleteVertexArrays;
extern PTR_GLBINDVERTEXARRAY glBindVertexArray;
extern PTR_GLENABLEVERTEXATTRIBARRAY glEnableVertexAttribArray;
extern PTR_GLDISABLEVERTEXATTRIBARRAY glDisableVertexAttribArray;
extern PTR_GLVERTEXATTRIBPOINTER glVertexAttribPointer;
extern PTR_GLUNIFORMMATRIX4FV glUniformMatrix4fv;
extern PTR_GLCLEARBUFFERFV	glClearBufferfv;
extern PTR_GLGETUNIFORMLOCATION glGetUniformLocation;
extern PTR_GLUNIFORM1I glUniform1i;
extern PTR_GLUNIFORM1F glUniform1f;
extern PTR_GLUNIFORM2F glUniform2f;
extern PTR_GLUNIFORM3F glUniform3f;
extern PTR_GLUNIFORM4F glUniform4f;
extern PTR_GLGENFRAMEBUFFERS	glGenFramebuffers;
extern PTR_GLBINDFRAMEBUFFER	glBindFramebuffer;
extern PTR_GLDELETEFRAMEBUFFERS	glDeleteFramebuffers;
extern PTR_GLRENDERBUFFERSTORAGE	glRenderbufferStorage;
extern PTR_GLFRAMEBUFFERRENDERBUFFER	glFramebufferRenderbuffer;
extern PTR_GLDELETERENDERBUFFERS	glDeleteRenderbuffers;
extern PTR_GLFRAMEBUFFERPARAMETERI	glFramebufferParameteri;
extern PTR_GLFRAMEBUFFERTEXTURE	glFramebufferTexture;
extern PTR_GLFRAMEBUFFERTEXTURE1D	glFramebufferTexture1D;
extern PTR_GLFRAMEBUFFERTEXTURE2D	glFramebufferTexture2D;
extern PTR_GLFRAMEBUFFERTEXTURE3D	glFramebufferTexture3D;
extern PTR_GLCHECKFRAMEBUFFERSTATUS	glCheckFramebufferStatus;
//extern PTR_GLACTIVETEXTURE		glActiveTexture;
extern PTR_GLDRAWBUFFERS		glDrawBuffers;
extern PTR_GLSHADERSOURCE  		glShaderSource;
extern PTR_GLCOMPILESHADER 		glCompileShader;
extern PTR_GLCREATEPROGRAM 		glCreateProgram;
extern PTR_GLATTACHSHADER  		glAttachShader;
extern PTR_GLLINKPROGRAM   		glLinkProgram;
extern PTR_GLUSEPROGRAM   		glUseProgram;
extern PTR_GLGETSHADER    		glGetShaderiv;
extern PTR_GLCREATESHADER  		glCreateShader;
extern PTR_GLGETSHADERINFOLOG 	glGetShaderInfoLog;
extern PTR_GLGENBUFFERS 		glGenBuffers;
extern PTR_GLBINDBUFFER 		glBindBuffer;
extern PTR_GLBUFFERDATA 		glBufferData;
extern PTR_GLBUFFERSUBDATA 		glBufferSubData;
//extern PTR_GLDRAWRANGEELEMENTS 	glDrawRangeElements;
extern PTR_GLGETSTRINGI			glGetStringi;


#define GLCheckError() GLCheckErrorInternal(__FILE__, __LINE__)


#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D

#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
#define GL_VERTEX_PROGRAM_TWO_SIDE        0x8643
#define GL_POINT_SPRITE                   0x8861
#define GL_COORD_REPLACE                  0x8862
#define GL_MAX_TEXTURE_COORDS             0x8871

#define GL_CLAMP_TO_EDGE                  0x812F

#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914

#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9

#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57


#endif


#endif


#endif
