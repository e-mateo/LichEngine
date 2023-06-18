#pragma once

#include "../../../Headers/Resources/Resource.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_1579378244772075015u_2769453275296748834() noexcept {
static rfk::NamespaceFragment fragment("Resources", 1579378244772075015u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Resources::Resource>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_1579378244772075015u_2769453275296748834(rfk::generated::getNamespaceFragment_1579378244772075015u_2769453275296748834());
 }
rfk::Class const& Resources::Resource::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Resource", 14025536381049257182u, sizeof(Resource), 1);
if (!initialized) {
initialized = true;
Resource::_rfk_registerChildClass<Resource>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Resource>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Resource>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Resource>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Resource>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Resource>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Resource>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Resources::Resource>() noexcept { return &Resources::Resource::staticGetArchetype(); }


