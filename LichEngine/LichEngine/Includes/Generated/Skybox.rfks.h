#pragma once

#include "../../../Headers/Camera/Skybox.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_9979533293161709597u_9591414181108641057() noexcept {
static rfk::NamespaceFragment fragment("CameraRender", 9979533293161709597u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getArchetype<CameraRender::SkyBox>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_9979533293161709597u_9591414181108641057(rfk::generated::getNamespaceFragment_9979533293161709597u_9591414181108641057());
 }
rfk::Class const& CameraRender::SkyBox::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("SkyBox", 13622962266137772198u, sizeof(SkyBox), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<Resources::Resource>(), static_cast<rfk::EAccessSpecifier>(1));
SkyBox::_rfk_registerChildClass<SkyBox>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SkyBox>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SkyBox>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SkyBox>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SkyBox>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SkyBox>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SkyBox>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<CameraRender::SkyBox>() noexcept { return &CameraRender::SkyBox::staticGetArchetype(); }


