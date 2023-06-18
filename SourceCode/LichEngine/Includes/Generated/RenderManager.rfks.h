#pragma once

#include "../../../Headers/Renderer/RenderManager.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_7834755036065876653u_85691592655410857() noexcept {
static rfk::NamespaceFragment fragment("Renderer", 7834755036065876653u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<Renderer::RenderManager>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_7834755036065876653u_85691592655410857(rfk::generated::getNamespaceFragment_7834755036065876653u_85691592655410857());
 }
rfk::Class const& Renderer::RenderManager::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("RenderManager", 17010417404763735611u, sizeof(RenderManager), 1);
if (!initialized) {
initialized = true;
RenderManager::_rfk_registerChildClass<RenderManager>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<RenderManager>>(),new rfk::NonMemberFunction<rfk::SharedPtr<RenderManager>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<RenderManager>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<RenderManager>>(),new rfk::NonMemberFunction<rfk::UniquePtr<RenderManager>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<RenderManager>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<Renderer::RenderManager>() noexcept { return &Renderer::RenderManager::staticGetArchetype(); }


