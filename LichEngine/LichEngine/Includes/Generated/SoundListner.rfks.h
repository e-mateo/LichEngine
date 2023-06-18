#pragma once

#include "../../../Headers/Sound/SoundListner.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_430029103769458876u_7360998903836367484() noexcept {
static rfk::NamespaceFragment fragment("SoundSystem", 430029103769458876u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<SoundSystem::SoundListner>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_430029103769458876u_7360998903836367484(rfk::generated::getNamespaceFragment_430029103769458876u_7360998903836367484());
 }
rfk::Class const& SoundSystem::SoundListner::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("SoundListner", 16607589753855756227u, sizeof(SoundListner), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
SoundListner::_rfk_registerChildClass<SoundListner>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SoundListner>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SoundListner>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SoundListner>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SoundListner>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SoundListner>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SoundListner>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<SoundSystem::SoundListner>() noexcept { return &SoundSystem::SoundListner::staticGetArchetype(); }


