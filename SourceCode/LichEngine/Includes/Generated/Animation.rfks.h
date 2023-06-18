#pragma once

#include "../../../Headers/Animation/Animation.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_5175265164474887853u_7940147060241716946() noexcept {
static rfk::NamespaceFragment fragment("AnimationSystem", 5175265164474887853u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<AnimationSystem::Animation>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_5175265164474887853u_7940147060241716946(rfk::generated::getNamespaceFragment_5175265164474887853u_7940147060241716946());
 }
rfk::Class const& AnimationSystem::Animation::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Animation", 1449942175296183986u, sizeof(Animation), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<Resources::Resource>(), static_cast<rfk::EAccessSpecifier>(1));
Animation::_rfk_registerChildClass<Animation>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Animation>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Animation>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Animation>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Animation>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Animation>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Animation>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<AnimationSystem::Animation>() noexcept { return &AnimationSystem::Animation::staticGetArchetype(); }


