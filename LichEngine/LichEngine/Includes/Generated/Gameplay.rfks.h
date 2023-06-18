#pragma once

#include "../../../Headers/Scripts/Gameplay.h"

#include <type_traits>
#include <Refureku/TypeInfo/Entity/DefaultEntityRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/ArchetypeRegisterer.h>
#include <Refureku/TypeInfo/Namespace/Namespace.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragment.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragmentRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateParameter.h>

namespace rfk::generated { static rfk::ArchetypeRegisterer const registerer_5555292336830033879u = Gameplay::staticGetArchetype(); }

rfk::Class const& Gameplay::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Gameplay", 5555292336830033879u, sizeof(Gameplay), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<Resources::Scripting>(), static_cast<rfk::EAccessSpecifier>(1));
Gameplay::_rfk_registerChildClass<Gameplay>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Gameplay>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Gameplay>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Gameplay>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Gameplay>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Gameplay>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Gameplay>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Gameplay>() noexcept { return &Gameplay::staticGetArchetype(); }


