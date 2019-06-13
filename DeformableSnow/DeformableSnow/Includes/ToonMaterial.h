#ifndef TOON_MATERIAL_H
#define TOON_MATERIAL_H

namespace Toon
{
	struct UniformDescription
	{	
		
	};

	/****************************************************************************
						Material class declaration
	****************************************************************************/
	class Material
	{
	public:
		Material() = default;
		Material(Material const&);
		Material& operator=(Material const&);
		Material(Material&&);
		Material& operator=(Material&&);
		~Material();
	public:
		
	private:
		
	};
};

#endif