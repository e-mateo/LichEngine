#pragma once

#include "../../../Headers/ToolBox.h"

#include <type_traits>
#include <Refureku/TypeInfo/Entity/DefaultEntityRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/ArchetypeRegisterer.h>
#include <Refureku/TypeInfo/Namespace/Namespace.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragment.h>
#include <Refureku/TypeInfo/Namespace/NamespaceFragmentRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateParameter.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateParameter.h>

namespace rfk::generated { static rfk::ArchetypeRegisterer const registerer_14150752295245285607u = SubShapeContainer::staticGetArchetype(); }

rfk::Class const& SubShapeContainer::staticGetArchetype() noexcept {
static bool initialized = false;
static rfk::Class type("SubShapeContainer", 14150752295245285607u, sizeof(SubShapeContainer), 1);
if (!initialized) {
initialized = true;
type.setDirectParentsCapacity(1);
type.addDirectParent(rfk::getArchetype<std::vector<Resources::SubModel *>>(), static_cast<rfk::EAccessSpecifier>(1));
SubShapeContainer::_rfk_registerChildClass<SubShapeContainer>(type);
static rfk::StaticMethod defaultSharedInstantiator("", 0u, rfk::getType<rfk::SharedPtr<SubShapeContainer>>(),new rfk::NonMemberFunction<rfk::SharedPtr<SubShapeContainer>()>(&rfk::internal::CodeGenerationHelpers::defaultSharedInstantiator<SubShapeContainer>),rfk::EMethodFlags::Default, nullptr);
type.addSharedInstantiator(defaultSharedInstantiator);
static rfk::StaticMethod defaultUniqueInstantiator("", 0u, rfk::getType<rfk::UniquePtr<SubShapeContainer>>(),new rfk::NonMemberFunction<rfk::UniquePtr<SubShapeContainer>()>(&rfk::internal::CodeGenerationHelpers::defaultUniqueInstantiator<SubShapeContainer>),rfk::EMethodFlags::Default, nullptr);
type.addUniqueInstantiator(defaultUniqueInstantiator);
type.setMethodsCapacity(0u); type.setStaticMethodsCapacity(0u); 
}
return type; }

template <> rfk::Archetype const* rfk::getArchetype<SubShapeContainer>() noexcept { return &SubShapeContainer::staticGetArchetype(); }

template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<VectorContainer>() noexcept {
static bool initialized = false;
static rfk::ClassTemplate type("VectorContainer", 6298535102091377239u, 1);
if (!initialized) {
initialized = true;
{ 
static rfk::TypeTemplateParameter templateParameter("T");
type.addTemplateParameter(templateParameter);
}
}return &type; }

namespace rfk::generated { static rfk::ArchetypeRegisterer const register_6298535102091377239u = *rfk::getArchetype<::VectorContainer>(); }


