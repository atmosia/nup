#include <stdio.h>
#include <stdlib.h>

#include "component.h"
#include "component/appearance.h"
#include "component/class.h"
#include "component/displacement.h"
#include "component/velocity.h"

#define ENTITY_COUNT 512

// TODO: use a better spare array
typedef struct {
	int mask[ENTITY_COUNT];
	Displacement displacement[ENTITY_COUNT];
	Velocity velocity[ENTITY_COUNT];
	Appearance appearance[ENTITY_COUNT];
	Class class[ENTITY_COUNT];
} World;

// TODO: optimize finding an empty slot
// TODO: fail in a sane way
unsigned
create_entity(World *world)
{
	unsigned entity;

	for (entity = 0; entity < ENTITY_COUNT; entity++) {
		if(world->mask[entity] == COMPONENT_NONE)
			return entity;
	}

	fprintf(stderr, "Error! No more entities left!\n");
	abort();
}

void
destroy_entity(World *world, unsigned entity)
{
	world->mask[entity] = COMPONENT_NONE;
}
