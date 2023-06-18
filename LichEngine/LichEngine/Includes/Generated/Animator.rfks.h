#pragma once

#include "../../../Headers/Animation/Animator.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_5175265164474887853u_17818616187330462649() noexcept {
static rfk::NamespaceFragment fragment("AnimationSystem", 5175265164474887853u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<AnimationSystem::Animator>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_5175265164474887853u_17818616187330462649(rfk::generated::getNamespaceFragment_5175265164474887853u_17818616187330462649());
 }
rfk::Class const& AnimationSystem::Animator::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Animator", 6482441720526294361u, sizeof(Animator), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
Animator::_rfk_registerChildClass<Animator>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Animator>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Animator>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Animator>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Animator>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Animator>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Animator>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<AnimationSystem::Animator>() noexcept { return &AnimationSystem::Animator::staticGetArchetype(); }


