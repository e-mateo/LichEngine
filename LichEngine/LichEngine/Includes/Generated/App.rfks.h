#pragma once

#include "../../../Headers/Core/App.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_10408655210973597161u_13510530985812758249() noexcept {
static rfk::NamespaceFragment fragment("Core", 10408655210973597161u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Core::App>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_10408655210973597161u_13510530985812758249(rfk::generated::getNamespaceFragment_10408655210973597161u_13510530985812758249());
 }
rfk::Class const& Core::App::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("App", 1144418839516962899u, sizeof(App), 1);
if (!initialized) {
initialized = true;
App::_rfk_registerChildClass<App>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<App>>(),new rfk::NonMemberFunction<rfk::SharedPtr<App>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<App>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<App>>(),new rfk::NonMemberFunction<rfk::UniquePtr<App>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<App>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Core::App>() noexcept { return &Core::App::staticGetArchetype(); }


