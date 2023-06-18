#pragma once

#include "../../../Headers/Core/Light.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_4354931014200351811u_14108079076828666207() noexcept {
static rfk::NamespaceFragment fragment("LightSystem", 4354931014200351811u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(2u);
fragment.addNestedEntity(*rfk::getArchetype<LightSystem::Light>());
fragment.addNestedEntity(*rfk::getEnum<LightSystem::TypeLight>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_4354931014200351811u_14108079076828666207(rfk::generated::getNamespaceFragment_4354931014200351811u_14108079076828666207());
 }
rfk::Class const& LightSystem::Light::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Light", 3609352763368957182u, sizeof(Light), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
Light::_rfk_registerChildClass<Light>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Light>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Light>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Light>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Light>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Light>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Light>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<LightSystem::Light>() noexcept { return &LightSystem::Light::staticGetArchetype(); }

template <> rfk::Enum const* rfk::getEnum<LightSystem::TypeLight>() noexcept
{
static bool initialized = false;
static rfk::Enum type("TypeLight", 263659807210368536u, rfk::getArchetype<int>());
if (!initialized) {
initialized = true;
rfk::EnumValue* enumValue = nullptr;
type.setEnumValuesCapacity(3);
enumValue = type.addEnumValue("DIR_LIGHT", 6734016298874096084u, 0);
enumValue = type.addEnumValue("SPOT_LIGHT", 9089753455881254215u, 1);
enumValue = type.addEnumValue("POINT_LIGHT", 16815027573428640509u, 2);
}
return &type; }

