#pragma once

#include "../../../Headers/Core/SpotLight.h"

#include <type_traits>
#include <Refureku/TypeInfo/Entity/DefaultEntityRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/ArchetypeRegisterer.h>
#include <Refureku/TypeInfo/Namespace/Namespace.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragment.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragmentRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateParameter.h>

namespace rfk::generated { 
 static rfk::NamespaceFragment const& getNamespaceFragment_4354931014200351811u_5967898427740990710() noexcept {
static rfk::NamespaceFragment fragment("LightSystem", 4354931014200351811u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<LightSystem::SpotLight>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_4354931014200351811u_5967898427740990710(rfk::generated::getNamespaceFragment_4354931014200351811u_5967898427740990710());
 }
rfk::Class const& LightSystem::SpotLight::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("SpotLight", 13568369944795354782u, sizeof(SpotLight), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<LightSystem::Light>(), static_cast<rfk::EAccessSpecifier>(1));
SpotLight::_rfk_registerChildClass<SpotLight>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SpotLight>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SpotLight>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SpotLight>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SpotLight>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SpotLight>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SpotLight>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<LightSystem::SpotLight>() noexcept { return &LightSystem::SpotLight::staticGetArchetype(); }


