#include "Util.hpp"
#include <glad/glad.h>
#include "Logger.hpp"
#include <glm/gtc/matrix_transform.hpp>

unsigned int Util::CreateTexture2D(std::string path, bool gamma) {
	return 0;
}

bool Util::PrintErrors(std::string location, std::string message) {
	INFO_LOG("Start Error Trace : ( {} )", message);

	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		std::string error;
		switch (errorCode) {
			case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
			case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
			case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
			case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
			case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
		}
		ERROR_LOG("[{}] at {}", error, location);
	}

	if (errorCode == GL_NO_ERROR) {
		INFO_LOG("No errors at {}", location);
		return false;
	}

	return true;
}

template <> float		Util::clamp(float value, float begin, float end);
template <> float		Util::fract(float value);
template <> glm::vec2	Util::fract(glm::vec2 value);
template <> glm::vec3	Util::fract(glm::vec3 value);
template <> glm::vec4	Util::fract(glm::vec4 value);
template <> float		Util::interpolate(float v1, float v2, float ratio);
template <> glm::vec2	Util::interpolate(glm::vec2 v1, glm::vec2 v2, float ratio);
template <> glm::vec3	Util::interpolate(glm::vec3 v1, glm::vec3 v2, float ratio);
template <> glm::vec4	Util::interpolate(glm::vec4 v1, glm::vec4 v2, float ratio);
