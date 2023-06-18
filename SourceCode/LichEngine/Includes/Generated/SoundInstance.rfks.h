#pragma once

#include "../../../Headers/Resources/SoundInstance.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_1579378244772075015u_2420644045114826714() noexcept {
static rfk::NamespaceFragment fragment("Resources", 1579378244772075015u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Resources::SoundInstance>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_1579378244772075015u_2420644045114826714(rfk::generated::getNamespaceFragment_1579378244772075015u_2420644045114826714());
 }
rfk::Class const& Resources::SoundInstance::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("SoundInstance", 8478327982358585762u, sizeof(SoundInstance), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<Resources::Resource>(), static_cast<rfk::EAccessSpecifier>(1));
SoundInstance::_rfk_registerChildClass<SoundInstance>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SoundInstance>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SoundInstance>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SoundInstance>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SoundInstance>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SoundInstance>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SoundInstance>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Resources::SoundInstance>() noexcept { return &Resources::SoundInstance::staticGetArchetype(); }


