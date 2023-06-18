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


#define Physics_RigidBody_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<RigidBody, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, RigidBody>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, RigidBody>());\
else\
{\
childClass.setFieldsCapacity(14u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< SceneManagement::Component>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< SceneManagement::Component>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("m_speed", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_speed") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_speed), &thisClass);\
field = childClass.addField("m_velocity", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_velocity") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_velocity), &thisClass);\
field = childClass.addField("m_angularVelocity", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_angularVelocity") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_angularVelocity), &thisClass);\
field = childClass.addField("m_inertiaTensor", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_inertiaTensor") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_inertiaTensor), &thisClass);\
field = childClass.addField("m_inertiaTensorRotation", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_inertiaTensorRotation") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_inertiaTensorRotation), &thisClass);\
field = childClass.addField("m_localCenterofMass", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_localCenterofMass") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_localCenterofMass), &thisClass);\
field = childClass.addField("m_globalCenterofMass", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_globalCenterofMass") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_globalCenterofMass), &thisClass);\
field = childClass.addField("m_isSleeping", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_isSleeping") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_isSleeping), &thisClass);\
field = childClass.addField("m_isKinematic", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_isKinematic") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_isKinematic), &thisClass);\
field = childClass.addField("m_useGravity", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_useGravity") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_useGravity), &thisClass);\
field = childClass.addField("m_mass", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_mass") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_mass), &thisClass);\
field = childClass.addField("m_drag", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_drag") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_drag), &thisClass);\
field = childClass.addField("m_angularDrag", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@m_angularDrag") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_angularDrag), &thisClass);\
field = childClass.addField("constraints", std::hash<std::string>()(std::string("c:@N@Physics@S@RigidBody@FI@constraints") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Physics::Constraints>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, constraints), &thisClass);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<SceneManagement::Component, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define Physics_Constraints_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<Constraints, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, Constraints>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, Constraints>());\
else\
{\
childClass.setFieldsCapacity(6u + 0); childClass.setStaticFieldsCapacity(0u + 0); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("PositionX", std::hash<std::string>()(std::string("c:@N@Physics@S@Constraints@FI@PositionX") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, PositionX), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((TitleReflectionProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] TitleReflectionProperty can't be applied to a rfk::EEntityKind::Field");static TitleReflectionProperty property_10925604995178704250u_0{"Constraints"};field->addProperty(property_10925604995178704250u_0);\
field = childClass.addField("PositionY", std::hash<std::string>()(std::string("c:@N@Physics@S@Constraints@FI@PositionY") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, PositionY), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((SameLineProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] SameLineProperty can't be applied to a rfk::EEntityKind::Field");static SameLineProperty property_10925606094690332461u_0;field->addProperty(property_10925606094690332461u_0);\
field = childClass.addField("PositionZ", std::hash<std::string>()(std::string("c:@N@Physics@S@Constraints@FI@PositionZ") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, PositionZ), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((SameLineProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] SameLineProperty can't be applied to a rfk::EEntityKind::Field");static SameLineProperty property_10925602796155447828u_0;field->addProperty(property_10925602796155447828u_0);\
field = childClass.addField("RotationX", std::hash<std::string>()(std::string("c:@N@Physics@S@Constraints@FI@RotationX") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, RotationX), &thisClass);\
field = childClass.addField("RotationY", std::hash<std::string>()(std::string("c:@N@Physics@S@Constraints@FI@RotationY") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, RotationY), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((SameLineProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] SameLineProperty can't be applied to a rfk::EEntityKind::Field");static SameLineProperty property_1466356844978415182u_0;field->addProperty(property_1466356844978415182u_0);\
field = childClass.addField("RotationZ", std::hash<std::string>()(std::string("c:@N@Physics@S@Constraints@FI@RotationZ") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, RotationZ), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((SameLineProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] SameLineProperty can't be applied to a rfk::EEntityKind::Field");static SameLineProperty property_1466355745466786971u_0;field->addProperty(property_1466355745466786971u_0);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(}\
\
public: LICH_ENGINE static rfk::Struct const& staticGetArchetype() noexcept;\
\
)\


#define File_RigidBody_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<Physics::Constraints>() noexcept;\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<Physics::RigidBody>() noexcept;\
template <> LICH_ENGINE rfk::Enum const* rfk::getEnum<Physics::ForceMode>() noexcept;\


