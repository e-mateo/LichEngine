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


#define CameraRender_Camera_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<Camera, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, Camera>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, Camera>());\
else\
{\
childClass.setFieldsCapacity(2u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< SceneManagement::Component>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< SceneManagement::Component>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("m_settings", std::hash<std::string>()(std::string("c:@N@CameraRender@S@Camera@FI@m_settings") + rfk::internal::getTypename<ChildClass>()), rfk::getType<CameraRender::CameraSettings>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_settings), &thisClass);\
field = childClass.addField("m_pSkyBox", std::hash<std::string>()(std::string("c:@N@CameraRender@S@Camera@FI@m_pSkyBox") + rfk::internal::getTypename<ChildClass>()), rfk::getType<CameraRender::SkyBox *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pSkyBox), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_17538280242454259878u_0{Resources::ResourceType::SKYBOX};field->addProperty(property_17538280242454259878u_0);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<SceneManagement::Component, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define CameraRender_CameraSettings_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<CameraSettings, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, CameraSettings>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, CameraSettings>());\
else\
{\
childClass.setFieldsCapacity(3u + 0); childClass.setStaticFieldsCapacity(0u + 0); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("cameraNear", std::hash<std::string>()(std::string("c:@N@CameraRender@S@CameraSettings@FI@cameraNear") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, cameraNear), &thisClass);\
field = childClass.addField("cameraFar", std::hash<std::string>()(std::string("c:@N@CameraRender@S@CameraSettings@FI@cameraFar") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, cameraFar), &thisClass);\
field = childClass.addField("fov", std::hash<std::string>()(std::string("c:@N@CameraRender@S@CameraSettings@FI@fov") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, fov), &thisClass);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(}\
\
public:  static rfk::Struct const& staticGetArchetype() noexcept;\
\
)\


#define File_Camera_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<CameraRender::CameraSettings>() noexcept;\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<CameraRender::Camera>() noexcept;\


