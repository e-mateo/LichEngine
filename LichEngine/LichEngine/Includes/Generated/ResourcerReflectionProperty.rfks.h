#pragma once

#include "../../../Headers/Resources/ResourcerReflectionProperty.h"

#include <type_traits>
#include <Refureku/TypeInfo/Entity/DefaultEntityRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/ArchetypeRegisterer.h>
#include <Refureku/TypeInfo/Namespace/Namespace.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragment.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragmentRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateParameter.h>

rfk::EEntityKind ResourceTypeProperty::getTargetEntityKind() const noexcept { return targetEntityKind; }
bool ResourceTypeProperty::getAllowMultiple() const noexcept { return allowMultiple; }
bool ResourceTypeProperty::getShouldInherit() const noexcept { return shouldInherit; }
static_assert(std::is_base_of_v<rfk::Property, ResourceTypeProperty>, "[Refureku] Can't attach rfk::PropertySettings property to ResourceTypeProperty as it doesn't inherit from rfk::Property.");
namespace rfk::generated { static rfk::ArchetypeRegisterer const registerer_7402117672923987894u = ResourceTypeProperty::staticGetArchetype(); }

rfk::Class const& ResourceTypeProperty::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("ResourceTypeProperty", 7402117672923987894u, sizeof(ResourceTypeProperty), 1);
if (!initialized) {
initialized = true;
type.setPropertiesCapacity(1);
static_assert((rfk::PropertySettings::targetEntityKind & rfk::EEntityKind::Class) != rfk::EEntityKind::Undefined, "[Refureku] rfk::PropertySettings can't be applied to a rfk::EEntityKind::Class");static rfk::PropertySettings property_7402117672923987894u_0{rfk::EEntityKind::Field,false,true};type.addProperty(property_7402117672923987894u_0);
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<rfk::Property>(), static_cast<rfk::EAccessSpecifier>(1));
ResourceTypeProperty::_rfk_registerChildClass<ResourceTypeProperty>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<ResourceTypeProperty>>(),new rfk::NonMemberFunction<rfk::SharedPtr<ResourceTypeProperty>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<ResourceTypeProperty>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<ResourceTypeProperty>>(),new rfk::NonMemberFunction<rfk::UniquePtr<ResourceTypeProperty>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<ResourceTypeProperty>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

rfk::Class const& ResourceTypeProperty::getArchetype() const noexcept { return ResourceTypeProperty::staticGetArchetype(); }

template <> rfk::Archetype const* rfk::getArchetype<ResourceTypeProperty>() noexcept { return &ResourceTypeProperty::staticGetArchetype(); }


