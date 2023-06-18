#pragma once

#include "../../../Headers/Resources/Texture.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_1579378244772075015u_10699164010179697036() noexcept {
static rfk::NamespaceFragment fragment("Resources", 1579378244772075015u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Resources::Texture>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_1579378244772075015u_10699164010179697036(rfk::generated::getNamespaceFragment_1579378244772075015u_10699164010179697036());
 }
rfk::Class const& Resources::Texture::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Texture", 12802431895961485513u, sizeof(Texture), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<Resources::Resource>(), static_cast<rfk::EAccessSpecifier>(1));
Texture::_rfk_registerChildClass<Texture>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Texture>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Texture>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Texture>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Texture>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Texture>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Texture>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Resources::Texture>() noexcept { return &Resources::Texture::staticGetArchetype(); }


