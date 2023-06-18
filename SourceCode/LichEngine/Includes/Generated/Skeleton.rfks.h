#pragma once

#include "../../../Headers/Animation/Skeleton.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_5175265164474887853u_14438174426996110901() noexcept {
static rfk::NamespaceFragment fragment("AnimationSystem", 5175265164474887853u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<AnimationSystem::Skeleton>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_5175265164474887853u_14438174426996110901(rfk::generated::getNamespaceFragment_5175265164474887853u_14438174426996110901());
 }
rfk::Class const& AnimationSystem::Skeleton::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Skeleton", 3075047900418669883u, sizeof(Skeleton), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<Resources::Resource>(), static_cast<rfk::EAccessSpecifier>(1));
Skeleton::_rfk_registerChildClass<Skeleton>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Skeleton>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Skeleton>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Skeleton>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Skeleton>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Skeleton>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Skeleton>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<AnimationSystem::Skeleton>() noexcept { return &AnimationSystem::Skeleton::staticGetArchetype(); }


