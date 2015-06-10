#ifdef HAKO_MODULE_OPENGL


#ifdef HAKO_PLATFORM_WIN32


#include "gl_includes_win32.h"
#include <stdio.h>


PTR_GLGENBUFFERS 				glGenBuffers;
PTR_GLBINDBUFFER 				glBindBuffer;
PTR_GLBUFFERDATA 				glBufferData;
PTR_GLBUFFERSUBDATA 			glBufferSubData;
PTR_GLDRAWRANGEELEMENTS 		glDrawRangeElements;
PTR_GLSHADERSOURCE				glShaderSource;
PTR_GLCOMPILESHADER				glCompileShader;
PTR_GLCREATEPROGRAM				glCreateProgram;
PTR_GLATTACHSHADER				glAttachShader;
PTR_GLLINKPROGRAM				glLinkProgram;
PTR_GLUSEPROGRAM				glUseProgram;
PTR_GLGETSHADER					glGetShaderiv;
PTR_GLCREATESHADER		 		glCreateShader;
PTR_GLGETSHADERINFOLOG 			glGetShaderInfoLog;
PTR_GLGENFRAMEBUFFERS			glGenFramebuffers;
PTR_GLBINDFRAMEBUFFER			glBindFramebuffer;
PTR_GLDELETEFRAMEBUFFERS		glDeleteFramebuffers;
PTR_GLRENDERBUFFERSTORAGE		glRenderbufferStorage;
PTR_GLFRAMEBUFFERRENDERBUFFER	glFramebufferRenderbuffer;
PTR_GLDELETERENDERBUFFERS		glDeleteRenderbuffers;
PTR_GLFRAMEBUFFERPARAMETERI		glFramebufferParameteri;
PTR_GLFRAMEBUFFERTEXTURE		glFramebufferTexture;
PTR_GLFRAMEBUFFERTEXTURE1D		glFramebufferTexture1D;
PTR_GLFRAMEBUFFERTEXTURE2D		glFramebufferTexture2D;
PTR_GLFRAMEBUFFERTEXTURE3D		glFramebufferTexture3D;
PTR_GLCHECKFRAMEBUFFERSTATUS	glCheckFramebufferStatus;
PTR_GLDRAWBUFFERS				glDrawBuffers;
PTR_GLACTIVETEXTURE				glActiveTexture;
PTR_GLGETUNIFORMLOCATION		glGetUniformLocation;
PTR_GLUNIFORM1I					glUniform1i;
PTR_GLUNIFORM1F					glUniform1f;
PTR_GLUNIFORM2F					glUniform2f;
PTR_GLUNIFORM3F					glUniform3f;
PTR_GLUNIFORM4F					glUniform4f;
PTR_GLCLEARBUFFERFV				glClearBufferfv;
PTR_GLUNIFORMMATRIX4FV			glUniformMatrix4fv;
PTR_GLVERTEXATTRIBPOINTER		glVertexAttribPointer;
PTR_GLENABLEVERTEXATTRIBARRAY	glEnableVertexAttribArray;
PTR_GLDISABLEVERTEXATTRIBARRAY	glDisableVertexAttribArray;
PTR_GLGENVERTEXARRAYS			glGenVertexArrays;
PTR_GLDELETEVERTEXARRAYS		glDeleteVertexArrays;
PTR_GLBINDVERTEXARRAY			glBindVertexArray;
PTR_GLGETATTRIBLOCATION			glGetAttribLocation;
PTR_GLBINDFRAGDATALOCATION		glBindFragDataLocation;
PTR_GLGETSTRINGI				glGetStringi;


#define HAKO_WGL_GETFUNCTION(func,typ) func = Hako::OpenGL::win32_get_function<typ>(#func)


namespace Hako
{
	namespace OpenGL
	{
		template <typename TFunction>
		TFunction win32_get_function(const char* name)
		{
			TFunction ret = (TFunction)wglGetProcAddress(name);
			if (!ret)
			{
				printf("missing OpenGL function: %s\n", name);
				return nullptr;
			}
			return ret;
		}


		void win32_load_extensions()
		{
			HAKO_WGL_GETFUNCTION(glClearBufferfv, PTR_GLCLEARBUFFERFV);
			HAKO_WGL_GETFUNCTION(glGetUniformLocation, PTR_GLGETUNIFORMLOCATION);
			HAKO_WGL_GETFUNCTION(glUniform1i, PTR_GLUNIFORM1I);
			HAKO_WGL_GETFUNCTION(glUniform1f, PTR_GLUNIFORM1F);
			HAKO_WGL_GETFUNCTION(glUniform2f, PTR_GLUNIFORM2F);
			HAKO_WGL_GETFUNCTION(glUniform3f, PTR_GLUNIFORM3F);
			HAKO_WGL_GETFUNCTION(glUniform4f, PTR_GLUNIFORM4F);
			HAKO_WGL_GETFUNCTION(glActiveTexture, PTR_GLACTIVETEXTURE);
			HAKO_WGL_GETFUNCTION(glGenFramebuffers, PTR_GLGENFRAMEBUFFERS);
			HAKO_WGL_GETFUNCTION(glBindFramebuffer, PTR_GLBINDFRAMEBUFFER);
			HAKO_WGL_GETFUNCTION(glDeleteFramebuffers, PTR_GLDELETEFRAMEBUFFERS);
			HAKO_WGL_GETFUNCTION(glRenderbufferStorage, PTR_GLRENDERBUFFERSTORAGE);
			HAKO_WGL_GETFUNCTION(glFramebufferRenderbuffer, PTR_GLFRAMEBUFFERRENDERBUFFER);
			HAKO_WGL_GETFUNCTION(glDeleteRenderbuffers, PTR_GLDELETERENDERBUFFERS);
			//HAKO_WGL_GETFUNCTION(glFramebufferParameteri,PTR_GLFRAMEBUFFERPARAMETERI);
			HAKO_WGL_GETFUNCTION(glFramebufferTexture, PTR_GLFRAMEBUFFERTEXTURE);
			HAKO_WGL_GETFUNCTION(glFramebufferTexture1D, PTR_GLFRAMEBUFFERTEXTURE1D);
			HAKO_WGL_GETFUNCTION(glFramebufferTexture2D, PTR_GLFRAMEBUFFERTEXTURE2D);
			HAKO_WGL_GETFUNCTION(glFramebufferTexture3D, PTR_GLFRAMEBUFFERTEXTURE3D);
			HAKO_WGL_GETFUNCTION(glCheckFramebufferStatus, PTR_GLCHECKFRAMEBUFFERSTATUS);
			HAKO_WGL_GETFUNCTION(glDrawBuffers, PTR_GLDRAWBUFFERS);
			HAKO_WGL_GETFUNCTION(glUniformMatrix4fv, PTR_GLUNIFORMMATRIX4FV);
			HAKO_WGL_GETFUNCTION(glVertexAttribPointer, PTR_GLVERTEXATTRIBPOINTER);
			HAKO_WGL_GETFUNCTION(glEnableVertexAttribArray, PTR_GLENABLEVERTEXATTRIBARRAY);
			HAKO_WGL_GETFUNCTION(glDisableVertexAttribArray, PTR_GLDISABLEVERTEXATTRIBARRAY);
			HAKO_WGL_GETFUNCTION(glGenVertexArrays, PTR_GLGENVERTEXARRAYS);
			HAKO_WGL_GETFUNCTION(glDeleteVertexArrays, PTR_GLDELETEVERTEXARRAYS);
			HAKO_WGL_GETFUNCTION(glBindVertexArray, PTR_GLBINDVERTEXARRAY);
			HAKO_WGL_GETFUNCTION(glGetAttribLocation, PTR_GLGETATTRIBLOCATION);
			HAKO_WGL_GETFUNCTION(glBindFragDataLocation, PTR_GLBINDFRAGDATALOCATION);
			HAKO_WGL_GETFUNCTION(glGetStringi, PTR_GLGETSTRINGI);
			HAKO_WGL_GETFUNCTION(glGenBuffers, PTR_GLGENBUFFERS);
			HAKO_WGL_GETFUNCTION(glBindBuffer, PTR_GLBINDBUFFER);
			HAKO_WGL_GETFUNCTION(glBufferData, PTR_GLBUFFERDATA);
			HAKO_WGL_GETFUNCTION(glBufferSubData, PTR_GLBUFFERSUBDATA);
			HAKO_WGL_GETFUNCTION(glDrawRangeElements, PTR_GLDRAWRANGEELEMENTS);
			HAKO_WGL_GETFUNCTION(glShaderSource, PTR_GLSHADERSOURCE);
			HAKO_WGL_GETFUNCTION(glCompileShader, PTR_GLCOMPILESHADER);
			HAKO_WGL_GETFUNCTION(glCreateProgram, PTR_GLCREATEPROGRAM);
			HAKO_WGL_GETFUNCTION(glAttachShader, PTR_GLATTACHSHADER);
			HAKO_WGL_GETFUNCTION(glLinkProgram, PTR_GLLINKPROGRAM);
			HAKO_WGL_GETFUNCTION(glUseProgram, PTR_GLUSEPROGRAM);
			HAKO_WGL_GETFUNCTION(glGetShaderiv, PTR_GLGETSHADER);
			HAKO_WGL_GETFUNCTION(glCreateShader, PTR_GLCREATESHADER);
			HAKO_WGL_GETFUNCTION(glGetShaderInfoLog, PTR_GLGETSHADERINFOLOG);
		}
	}
}


#endif


#endif
