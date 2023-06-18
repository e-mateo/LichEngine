#pragma once

#include "../../../Headers/Resources/Shape.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_1579378244772075015u_7292420593365283291() noexcept {
static rfk::NamespaceFragment fragment("Resources", 1579378244772075015u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Resources::SubModel>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_1579378244772075015u_7292420593365283291(rfk::generated::getNamespaceFragment_1579378244772075015u_7292420593365283291());
 }
rfk::Struct const& Resources::SubModel::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Struct type("SubModel", 9900567603211223345u, sizeof(SubModel), 0);
if (!initialized) {
initialized = true;
SubModel::_rfk_registerChildClass<SubModel>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SubModel>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SubModel>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SubModel>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SubModel>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SubModel>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SubModel>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Resources::SubModel>() noexcept { return &Resources::SubModel::staticGetArchetype(); }


