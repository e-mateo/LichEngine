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


#define LightSystem_Light_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<Light, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, Light>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, Light>());\
else\
{\
childClass.setFieldsCapacity(5u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< SceneManagement::Component>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< SceneManagement::Component>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("p_generateShadow", std::hash<std::string>()(std::string("c:@N@LightSystem@S@Light@FI@p_generateShadow") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(2), offsetof(ChildClass, p_generateShadow), &thisClass);\
field = childClass.addField("p_intensity", std::hash<std::string>()(std::string("c:@N@LightSystem@S@Light@FI@p_intensity") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(2), offsetof(ChildClass, p_intensity), &thisClass);\
field = childClass.addField("p_ambient", std::hash<std::string>()(std::string("c:@N@LightSystem@S@Light@FI@p_ambient") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(2), offsetof(ChildClass, p_ambient), &thisClass);\
field = childClass.addField("p_color", std::hash<std::string>()(std::string("c:@N@LightSystem@S@Light@FI@p_color") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector4D>(), static_cast<rfk::EFieldFlags>(2), offsetof(ChildClass, p_color), &thisClass);\
field = childClass.addField("p_type", std::hash<std::string>()(std::string("c:@N@LightSystem@S@Light@FI@p_type") + rfk::internal::getTypename<ChildClass>()), rfk::getType<LightSystem::TypeLight>(), static_cast<rfk::EFieldFlags>(2), offsetof(ChildClass, p_type), &thisClass);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<SceneManagement::Component, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define File_Light_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<LightSystem::Light>() noexcept;\
template <> LICH_ENGINE rfk::Enum const* rfk::getEnum<LightSystem::TypeLight>() noexcept;\


