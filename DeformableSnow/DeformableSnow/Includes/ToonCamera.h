#ifndef TOON_CAMERA_H
#define TOON_CAMERA_H

#include <glm/vec3.hpp>

namespace Toon
{
	/****************************************************************************
							Camera class declaration
	****************************************************************************/
	class Camera
	{
	private:
		glm::vec3	position;
		glm::vec3	direction;
		float		speed;
	public:
		Camera();
		Camera(Camera const &);
		Camera(Camera&&);
		~Camera();
		Camera& operator=(Camera const &);
		Camera& operator=(Camera&&);

		void processInput( int key, int button );
	};
};

#endif