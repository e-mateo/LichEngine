#pragma once

#include "../../../Headers/Sound/SoundEvent.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_430029103769458876u_5227319392429988941() noexcept {
static rfk::NamespaceFragment fragment("SoundSystem", 430029103769458876u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<SoundSystem::SoundEvent>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_430029103769458876u_5227319392429988941(rfk::generated::getNamespaceFragment_430029103769458876u_5227319392429988941());
 }
rfk::Class const& SoundSystem::SoundEvent::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("SoundEvent", 1672302103019641874u, sizeof(SoundEvent), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
SoundEvent::_rfk_registerChildClass<SoundEvent>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SoundEvent>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SoundEvent>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SoundEvent>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SoundEvent>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SoundEvent>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SoundEvent>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<SoundSystem::SoundEvent>() noexcept { return &SoundSystem::SoundEvent::staticGetArchetype(); }


