#pragma once

#include "../../../Headers/Scene/SceneManager.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_15553846452275018029u_17534914929505472818() noexcept {
static rfk::NamespaceFragment fragment("SceneManagement", 15553846452275018029u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<SceneManagement::SceneManager>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_15553846452275018029u_17534914929505472818(rfk::generated::getNamespaceFragment_15553846452275018029u_17534914929505472818());
 }
rfk::Class const& SceneManagement::SceneManager::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("SceneManager", 9608859786445203235u, sizeof(SceneManager), 1);
if (!initialized) {
initialized = true;
SceneManager::_rfk_registerChildClass<SceneManager>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SceneManager>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SceneManager>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SceneManager>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SceneManager>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SceneManager>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SceneManager>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<SceneManagement::SceneManager>() noexcept { return &SceneManagement::SceneManager::staticGetArchetype(); }


