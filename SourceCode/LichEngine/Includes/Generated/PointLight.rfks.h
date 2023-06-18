#pragma once

#include "../../../Headers/Core/PointLight.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_4354931014200351811u_14537008704944596424() noexcept {
static rfk::NamespaceFragment fragment("LightSystem", 4354931014200351811u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<LightSystem::PointLight>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_4354931014200351811u_14537008704944596424(rfk::generated::getNamespaceFragment_4354931014200351811u_14537008704944596424());
 }
rfk::Class const& LightSystem::PointLight::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("PointLight", 14134396211208731184u, sizeof(PointLight), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<LightSystem::Light>(), static_cast<rfk::EAccessSpecifier>(1));
PointLight::_rfk_registerChildClass<PointLight>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<PointLight>>(),new rfk::NonMemberFunction<rfk::SharedPtr<PointLight>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<PointLight>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<PointLight>>(),new rfk::NonMemberFunction<rfk::UniquePtr<PointLight>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<PointLight>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<LightSystem::PointLight>() noexcept { return &LightSystem::PointLight::staticGetArchetype(); }


