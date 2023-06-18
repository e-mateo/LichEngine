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


#define AnimationSystem_Animator_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<Animator, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, Animator>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, Animator>());\
else\
{\
childClass.setFieldsCapacity(3u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< SceneManagement::Component>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< SceneManagement::Component>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("m_pSkeleton", std::hash<std::string>()(std::string("c:@N@AnimationSystem@S@Animator@FI@m_pSkeleton") + rfk::internal::getTypename<ChildClass>()), rfk::getType<AnimationSystem::Skeleton *>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pSkeleton), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_4537128769328617365u_0{Resources::ResourceType::SKELETON};field->addProperty(property_4537128769328617365u_0);\
field = childClass.addField("m_speed", std::hash<std::string>()(std::string("c:@N@AnimationSystem@S@Animator@FI@m_speed") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_speed), &thisClass);\
field = childClass.addField("m_pAnimations", std::hash<std::string>()(std::string("c:@N@AnimationSystem@S@Animator@FI@m_pAnimations") + rfk::internal::getTypename<ChildClass>()), rfk::getType<VectorContainer<AnimationSystem::Animation>>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_pAnimations), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_15886713478630115237u_0{Resources::ResourceType::ANIMATION};field->addProperty(property_15886713478630115237u_0);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<SceneManagement::Component, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define File_Animator_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<AnimationSystem::Animator>() noexcept;\


