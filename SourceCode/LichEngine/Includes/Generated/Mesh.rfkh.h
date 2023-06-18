#pragma once

#include "EntityMacros.h"

#include <Refureku/TypeInfo/Entity/EEntityKind.h>
#include <string>
#include <Refureku/Misc/CodeGenerationHelpers.h>
#include <Refureku/Misc/DisableWarningMacros.h>
#include <Refureku/TypeInfo/Functions/Method.h>
#include <Refureku/TypeInfo/Functions/StaticMethod.h>
#include <Refureku/TypeInfo/Variables/Field.h>
#include <Refureku/TypeInfo/Variables/StaticField.h>
#include <Refureku/TypeInfo/Archetypes/Enum.h>
#include <Refureku/TypeInfo/Archetypes/EnumValue.h>
#include <Refureku/TypeInfo/Variables/Variable.h>
#include <Refureku/TypeInfo/Functions/Function.h>
#include <Refureku/TypeInfo/Archetypes/Template/ClassTemplate.h>
#include <Refureku/TypeInfo/Archetypes/Template/ClassTemplateInstantiation.h>
#include <Refureku/TypeInfo/Archetypes/Template/ClassTemplateInstantiationRegisterer.h>
#include <Refureku/TypeInfo/Archetypes/Template/TypeTemplateArgument.h>
#include <Refureku/TypeInfo/Archetypes/Template/NonTypeTemplateArgument.h>
#include <Refureku/TypeInfo/Archetypes/Template/TemplateTemplateArgument.h>


#define Renderer_Mesh_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<Mesh, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, Mesh>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, Mesh>());\
else\
{\
childClass.setFieldsCapacity(2u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< SceneManagement::Component>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< SceneManagement::Component>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("m_pModel", std::hash<std::string>()(std::string("c:@N@Renderer@S@Mesh@FI@m_pModel") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Model *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pModel), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_388601229820314547u_0{Resources::ResourceType::MODEL};field->addProperty(property_388601229820314547u_0);\
field = childClass.addField("m_pMaterial", std::hash<std::string>()(std::string("c:@N@Renderer@S@Mesh@FI@m_pMaterial") + rfk::internal::getTypename<ChildClass>()), rfk::getType<VectorContainer<Resources::Material>>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pMaterial), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_16148916361449181435u_0{Resources::ResourceType::MATERIAL};field->addProperty(property_16148916361449181435u_0);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<SceneManagement::Component, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define File_Mesh_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<Renderer::Mesh>() noexcept;\


