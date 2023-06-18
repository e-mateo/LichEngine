#pragma once

#include "../../../Headers/Camera/Camera.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_9979533293161709597u_10473379396027992868() noexcept {
static rfk::NamespaceFragment fragment("CameraRender", 9979533293161709597u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(2u);
fragment.addNestedEntity(*rfk::getArchetype<CameraRender::CameraSettings>());
fragment.addNestedEntity(*rfk::getArchetype<CameraRender::Camera>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_9979533293161709597u_10473379396027992868(rfk::generated::getNamespaceFragment_9979533293161709597u_10473379396027992868());
 }
rfk::Struct const& CameraRender::CameraSettings::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Struct type("CameraSettings", 16807391073263883646u, sizeof(CameraSettings), 0);
if (!initialized) {
initialized = true;
CameraSettings::_rfk_registerChildClass<CameraSettings>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<CameraSettings>>(),new rfk::NonMemberFunction<rfk::SharedPtr<CameraSettings>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<CameraSettings>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<CameraSettings>>(),new rfk::NonMemberFunction<rfk::UniquePtr<CameraSettings>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<CameraSettings>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<CameraRender::CameraSettings>() noexcept { return &CameraRender::CameraSettings::staticGetArchetype(); }

rfk::Class const& CameraRender::Camera::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("Camera", 11512118111706902611u, sizeof(Camera), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<SceneManagement::Component>(), static_cast<rfk::EAccessSpecifier>(1));
Camera::_rfk_registerChildClass<Camera>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<Camera>>(),new rfk::NonMemberFunction<rfk::SharedPtr<Camera>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<Camera>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<Camera>>(),new rfk::NonMemberFunction<rfk::UniquePtr<Camera>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<Camera>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<CameraRender::Camera>() noexcept { return &CameraRender::Camera::staticGetArchetype(); }


