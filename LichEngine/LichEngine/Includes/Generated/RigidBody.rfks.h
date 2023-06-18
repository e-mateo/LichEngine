#pragma once

#include "../../../Headers/Physics/RigidBody.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_13372167183821708463u_13257599039739381689() noexcept {
static rfk::NamespaceFragment fragment("Physics", 13372167183821708463u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(3u);
fragment.addNestedEntity(*rfk::getArchetype<Physics::Constraints>());
fragment.addNestedEntity(*rfk::getArchetype<Physics::RigidBody>());
fragment.addNestedEntity(*rfk::getEnum<Physics::ForceMode>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_13372167183821708463u_13257599039739381689(rfk::generated::getNamespaceFragment_13372167183821708463u_13257599039739381689());
 }
rfk::Struct const& Physics::Constraints::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Struct type("Constraints", 16763887777327255154u, sizeof(Constraints), 0);
if (!initialized) {
initialized = true;
Constraints::_rfk_registerChildClass<Constraints>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Constraints>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Constraints>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Constraints>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Constraints>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Constraints>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Constraints>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Physics::Constraints>() noexcept { return &Physics::Constraints::staticGetArchetype(); }

rfk::Class const& Physics::RigidBody::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("RigidBody", 10464726204242517853u, sizeof(RigidBody), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
RigidBody::_rfk_registerChildClass<RigidBody>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<RigidBody>>(),new rfk::NonMemberFunction<rfk::SharedPtr<RigidBody>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<RigidBody>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<RigidBody>>(),new rfk::NonMemberFunction<rfk::UniquePtr<RigidBody>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<RigidBody>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Physics::RigidBody>() noexcept { return &Physics::RigidBody::staticGetArchetype(); }

template <> rfk::Enum const* rfk::getEnum<Physics::ForceMode>() noexcept
{
static bool initialized = false;
static rfk::Enum type("ForceMode", 14992040091751589972u, rfk::getArchetype<int>());
if (!initialized) {
initialized = true;
rfk::EnumValue* enumValue = nullptr;
type.setEnumValuesCapacity(3);
enumValue = type.addEnumValue("FORCE", 8072927307745472911u, 0);
enumValue = type.addEnumValue("IMPULSE", 8235485625719952807u, 1);
enumValue = type.addEnumValue("VELOCITY_CHANGE", 14758820601129872976u, 2);
}
return &type; }

