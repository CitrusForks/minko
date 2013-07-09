#include "SizeOverTime.hpp"
#include "minko/particle/ParticleData.hpp"
#include "minko/particle/sampler/Sampler.hpp"
#include "minko/particle/tools/VertexComponentFlags.hpp"

using namespace minko::particle;
using namespace minko::particle::modifier;

void
SizeOverTime::update(std::vector<ParticleData>& 	particles,
 					 float							timeStep) const
{
	return;
}

unsigned int
SizeOverTime::getNeededComponents() const
{
	return VertexComponentFlags::TIME;
}