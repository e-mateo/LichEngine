#pragma once

#include "../../../Headers/Physics/Collider.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_13372167183821708463u_10128467214788755254() noexcept {
static rfk::NamespaceFragment fragment("Physics", 13372167183821708463u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(3u);
fragment.addNestedEntity(*rfk::getArchetype<Physics::ColliderShape>());
fragment.addNestedEntity(*rfk::getArchetype<Physics::Collider>());
fragment.addNestedEntity(*rfk::getEnum<Physics::ShapeType>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_13372167183821708463u_10128467214788755254(rfk::generated::getNamespaceFragment_13372167183821708463u_10128467214788755254());
 }
rfk::Struct const& Physics::ColliderShape::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Struct type("ColliderShape", 1044490429373461499u, sizeof(ColliderShape), 0);
if (!initialized) {
initialized = true;
ColliderShape::_rfk_registerChildClass<ColliderShape>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<ColliderShape>>(),new rfk::NonMemberFunction<rfk::SharedPtr<ColliderShape>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<ColliderShape>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<ColliderShape>>(),new rfk::NonMemberFunction<rfk::UniquePtr<ColliderShape>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<ColliderShape>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Physics::ColliderShape>() noexcept { return &Physics::ColliderShape::staticGetArchetype(); }

rfk::Class const& Physics::Collider::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Collider", 6111012940107360062u, sizeof(Collider), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
Collider::_rfk_registerChildClass<Collider>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Collider>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Collider>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Collider>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Collider>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Collider>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Collider>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Physics::Collider>() noexcept { return &Physics::Collider::staticGetArchetype(); }

template <> rfk::Enum const* rfk::getEnum<Physics::ShapeType>() noexcept
{
static bool initialized = false;
static rfk::Enum type("ShapeType", 4833201984373331205u, rfk::getArchetype<int>());
if (!initialized) {
initialized = true;
rfk::EnumValue* enumValue = nullptr;
type.setEnumValuesCapacity(4);
enumValue = type.addEnumValue("Plane", 18276809084536005255u, 0);
enumValue = type.addEnumValue("Box", 12247804222211003296u, 1);
enumValue = type.addEnumValue("Sphere", 12070310965627198922u, 2);
enumValue = type.addEnumValue("Capsule", 15944946017625584370u, 3);
}
return &type; }

