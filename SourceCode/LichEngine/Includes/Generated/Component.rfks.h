#pragma once

#include "../../../Headers/Scene/Component.h"

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
 static rfk::NamespaceFragment const& getNamespaceFragment_15553846452275018029u_855553336263952092() noexcept {
static rfk::NamespaceFragment fragment("SceneManagement", 15553846452275018029u);
static bool initialized = false;
if (!initialized) {
initialized = true;
fragment.setNestedEntitiesCapacity(1u);
fragment.addNestedEntity(*rfk::getEnum<SceneManagement::ComponentType>());
}
return fragment; }
static rfk::NamespaceFragmentRegisterer const namespaceFragmentRegisterer_15553846452275018029u_855553336263952092(rfk::generated::getNamespaceFragment_15553846452275018029u_855553336263952092());
 }
template <> rfk::Enum const* rfk::getEnum<SceneManagement::ComponentType>() noexcept
{
static bool initialized = false;
static rfk::Enum type("ComponentType", 14623296922385331689u, rfk::getArchetype<int>());
if (!initialized) {
initialized = true;
rfk::EnumValue* enumValue = nullptr;
type.setEnumValuesCapacity(13);
enumValue = type.addEnumValue("CAMERA", 14003060472371689084u, 0);
enumValue = type.addEnumValue("DIR_LIGHT", 17099391661318353321u, 1);
enumValue = type.addEnumValue("POINT_LIGHT", 1616420653247908584u, 2);
enumValue = type.addEnumValue("SPOT_LIGHT", 15534436570985228504u, 3);
enumValue = type.addEnumValue("MESH", 11923872943195593230u, 4);
enumValue = type.addEnumValue("RIGIDBODY", 17093893049913176994u, 5);
enumValue = type.addEnumValue("COLLIDER", 13760649855220147079u, 6);
enumValue = type.addEnumValue("ANIMATOR", 4423481619760688462u, 7);
enumValue = type.addEnumValue("SCRIPTING", 5000725976789843900u, 8);
enumValue = type.addEnumValue("SOUNDLISTNER", 5349818978661323775u, 9);
enumValue = type.addEnumValue("SOUNDEVENT", 6845494729791428566u, 10);
enumValue = type.addEnumValue("TEXT", 17165346922201229692u, 11);
enumValue = type.addEnumValue("IMAGE", 3451843529799973040u, 12);
}
return &type; }

