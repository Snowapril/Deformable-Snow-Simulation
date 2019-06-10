#ifndef TOON_STATIC_CAMERA_H
#define TOON_STATIC_CAMERA_H

#include <glm/vec3.hpp>

namespace Toon
{
	/****************************************************************************
							Camera class declaration
	****************************************************************************/
	class StaticCamera
	{
	private:
		glm::vec3	position;
		glm::vec3	direction;
	public:
		StaticCamera();
		StaticCamera(StaticCamera const &);
		StaticCamera(StaticCamera&&);
		~StaticCamera();
		StaticCamera& operator=(StaticCamera const &);
		StaticCamera& operator=(StaticCamera&&);
	};
};

#endif