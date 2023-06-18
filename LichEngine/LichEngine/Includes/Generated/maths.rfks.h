#pragma once

#include "../../../Headers/maths.h"

#include <type_traits>
#include <Refureku/TypeInfo/Entity/DefaultEntityRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/ArchetypeRegisterer.h>
#include <Refureku/TypeInfo/Namespace/Namespace.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragment.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragmentRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateParameter.h>

namespace rfk::generated { static rfk::ArchetypeRegisterer const registerer_2919851702505136134u = Vector2D::staticGetArchetype(); }

rfk::Class const& Vector2D::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Vector2D", 2919851702505136134u, sizeof(Vector2D), 1);
if (!initialized) {
initialized = true;
Vector2D::_rfk_registerChildClass<Vector2D>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Vector2D>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Vector2D>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Vector2D>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Vector2D>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Vector2D>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Vector2D>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Vector2D>() noexcept { return &Vector2D::staticGetArchetype(); }

namespace rfk::generated { static rfk::ArchetypeRegisterer const registerer_2920676336226105159u = Vector3D::staticGetArchetype(); }

rfk::Class const& Vector3D::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Vector3D", 2920676336226105159u, sizeof(Vector3D), 1);
if (!initialized) {
initialized = true;
Vector3D::_rfk_registerChildClass<Vector3D>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Vector3D>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Vector3D>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Vector3D>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Vector3D>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Vector3D>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Vector3D>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Vector3D>() noexcept { return &Vector3D::staticGetArchetype(); }

namespace rfk::generated { static rfk::ArchetypeRegisterer const registerer_2921764852737844824u = Vector4D::staticGetArchetype(); }

rfk::Class const& Vector4D::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Vector4D", 2921764852737844824u, sizeof(Vector4D), 1);
if (!initialized) {
initialized = true;
Vector4D::_rfk_registerChildClass<Vector4D>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Vector4D>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Vector4D>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Vector4D>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Vector4D>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Vector4D>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Vector4D>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Vector4D>() noexcept { return &Vector4D::staticGetArchetype(); }


