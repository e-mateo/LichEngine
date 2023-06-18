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


#define CameraRender_SkyBox_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<SkyBox, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, SkyBox>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, SkyBox>());\
else\
{\
childClass.setFieldsCapacity(6u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< Resources::Resource>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< Resources::Resource>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("m_top", std::hash<std::string>()(std::string("c:@N@CameraRender@S@SkyBox@FI@m_top") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_top), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_14481278095669603252u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_14481278095669603252u_0);\
field = childClass.addField("m_bottom", std::hash<std::string>()(std::string("c:@N@CameraRender@S@SkyBox@FI@m_bottom") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_bottom), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_429960284246927442u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_429960284246927442u_0);\
field = childClass.addField("m_right", std::hash<std::string>()(std::string("c:@N@CameraRender@S@SkyBox@FI@m_right") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_right), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_9747574467278490221u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_9747574467278490221u_0);\
field = childClass.addField("m_left", std::hash<std::string>()(std::string("c:@N@CameraRender@S@SkyBox@FI@m_left") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_left), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_12768262421432796216u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_12768262421432796216u_0);\
field = childClass.addField("m_front", std::hash<std::string>()(std::string("c:@N@CameraRender@S@SkyBox@FI@m_front") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_front), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_1666983002500889760u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_1666983002500889760u_0);\
field = childClass.addField("m_back", std::hash<std::string>()(std::string("c:@N@CameraRender@S@SkyBox@FI@m_back") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Resources::Texture *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_back), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_11746085455488828266u_0{Resources::ResourceType::TEXTURE};field->addProperty(property_11746085455488828266u_0);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<Resources::Resource, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define File_Skybox_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<CameraRender::SkyBox>() noexcept;\


