#pragma once

#include "../../../Headers/Scene/GameObject.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_15553846452275018029u_6203383530852279564() noexcept {
static rfk::NamespaceFragment fragment("SceneManagement", 15553846452275018029u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<SceneManagement::GameObject>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_15553846452275018029u_6203383530852279564(rfk::generated::getNamespaceFragment_15553846452275018029u_6203383530852279564());
 }
rfk::Class const& SceneManagement::GameObject::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("GameObject", 13431061602174192045u, sizeof(GameObject), 1);
if (!initialized) {
initialized = true;
GameObject::_rfk_registerChildClass<GameObject>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<GameObject>>(),new rfk::NonMemberFunction<rfk::SharedPtr<GameObject>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<GameObject>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<GameObject>>(),new rfk::NonMemberFunction<rfk::UniquePtr<GameObject>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<GameObject>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<SceneManagement::GameObject>() noexcept { return &SceneManagement::GameObject::staticGetArchetype(); }


