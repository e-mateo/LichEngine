#pragma once

#include "../../../Headers/Physics/Transform.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_13372167183821708463u_7264535564145900726() noexcept {
static rfk::NamespaceFragment fragment("Physics", 13372167183821708463u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Physics::Transform>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_13372167183821708463u_7264535564145900726(rfk::generated::getNamespaceFragment_13372167183821708463u_7264535564145900726());
 }
rfk::Class const& Physics::Transform::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Transform", 2564846424734180374u, sizeof(Transform), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
Transform::_rfk_registerChildClass<Transform>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Transform>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Transform>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Transform>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Transform>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Transform>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Transform>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Physics::Transform>() noexcept { return &Physics::Transform::staticGetArchetype(); }


