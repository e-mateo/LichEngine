#pragma once

#include "../../../Headers/IntegrationTest.h"

#include <type_traits>
#include <Refureku/TypeInfo/Entity/DefaultEntityRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/ArchetypeRegisterer.h>
#include <Refureku/TypeInfo/Namespace/Namespace.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragment.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragmentRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateParameter.h>

template <> rfk::Enum const* rfk::getEnum<IntegrationTest>() noexcept
{
static bool initialized = false;
static rfk::Enum type("IntegrationTest", 2823379867442659773u, rfk::getArchetype<int>());
if (!initialized) {
initialized = true;
}
return &type; }
namespace rfk::generated { static rfk::ArchetypeRegisterer const registerer_2823379867442659773u = *rfk::getEnum<IntegrationTest>(); }

