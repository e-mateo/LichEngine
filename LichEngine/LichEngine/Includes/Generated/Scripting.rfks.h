#pragma once

#include "../../../Headers/Resources/Scripting.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_1579378244772075015u_17081650463229888091() noexcept {
static rfk::NamespaceFragment fragment("Resources", 1579378244772075015u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Resources::Scripting>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_1579378244772075015u_17081650463229888091(rfk::generated::getNamespaceFragment_1579378244772075015u_17081650463229888091());
 }
rfk::Class const& Resources::Scripting::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Scripting", 12751403940423992155u, sizeof(Scripting), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
Scripting::_rfk_registerChildClass<Scripting>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Scripting>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Scripting>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Scripting>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Scripting>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Scripting>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Scripting>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Resources::Scripting>() noexcept { return &Resources::Scripting::staticGetArchetype(); }


