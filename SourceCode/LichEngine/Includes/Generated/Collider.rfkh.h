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


#define Physics_Collider_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<Collider, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, Collider>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, Collider>());\
else\
{\
childClass.setFieldsCapacity(6u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< SceneManagement::Component>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< SceneManagement::Component>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("m_shape", std::hash<std::string>()(std::string("c:@N@Physics@S@Collider@FI@m_shape") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Physics::ColliderShape>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_shape), &thisClass);\
field = childClass.addField("m_offset", std::hash<std::string>()(std::string("c:@N@Physics@S@Collider@FI@m_offset") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_offset), &thisClass);\
field = childClass.addField("m_staticFriction", std::hash<std::string>()(std::string("c:@N@Physics@S@Collider@FI@m_staticFriction") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_staticFriction), &thisClass);\
field = childClass.addField("m_dynamicFriction", std::hash<std::string>()(std::string("c:@N@Physics@S@Collider@FI@m_dynamicFriction") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_dynamicFriction), &thisClass);\
field = childClass.addField("m_restitution", std::hash<std::string>()(std::string("c:@N@Physics@S@Collider@FI@m_restitution") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_restitution), &thisClass);\
field = childClass.addField("m_isTrigger", std::hash<std::string>()(std::string("c:@N@Physics@S@Collider@FI@m_isTrigger") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_isTrigger), &thisClass);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<SceneManagement::Component, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define Physics_ColliderShape_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<ColliderShape, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, ColliderShape>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, ColliderShape>());\
else\
{\
childClass.setFieldsCapacity(2u + 0); childClass.setStaticFieldsCapacity(0u + 0); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("type", std::hash<std::string>()(std::string("c:@N@Physics@S@ColliderShape@FI@type") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Physics::ShapeType>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, type), &thisClass);\
field = childClass.addField("scale", std::hash<std::string>()(std::string("c:@N@Physics@S@ColliderShape@FI@scale") + rfk::internal::getTypename<ChildClass>()), rfk::getType<Vector3D>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, scale), &thisClass);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(}\
\
public:  static rfk::Struct const& staticGetArchetype() noexcept;\
\
)\


#define File_Collider_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<Physics::ColliderShape>() noexcept;\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<Physics::Collider>() noexcept;\
template <> LICH_ENGINE rfk::Enum const* rfk::getEnum<Physics::ShapeType>() noexcept;\


