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


#define SoundSystem_SoundEvent_GENERATED	\
RFK_UNPACK_IF_NOT_PARSING(friend rfk::internal::CodeGenerationHelpers;\
friend rfk::internal::implements_template1__rfk_registerChildClass<SoundEvent, void, void(rfk::Struct&)>; \
\
private: template <typename ChildClass> static void _rfk_registerChildClass(rfk::Struct& childClass) noexcept {\
rfk::Struct const& thisClass = staticGetArchetype();\
if constexpr (!std::is_same_v<ChildClass, SoundEvent>)const_cast<rfk::Struct&>(thisClass).addSubclass(childClass, rfk::internal::CodeGenerationHelpers::computeClassPointerOffset<ChildClass, SoundEvent>());\
else\
{\
childClass.setFieldsCapacity(6u + rfk::internal::CodeGenerationHelpers::getReflectedFieldsCount< SceneManagement::Component>()); childClass.setStaticFieldsCapacity(0u + rfk::internal::CodeGenerationHelpers::getReflectedStaticFieldsCount< SceneManagement::Component>()); \
}\
[[maybe_unused]] rfk::Field* field = nullptr; [[maybe_unused]] rfk::StaticField* staticField = nullptr;\
)\
__RFK_DISABLE_WARNING_PUSH \
__RFK_DISABLE_WARNING_OFFSETOF \
RFK_UNPACK_IF_NOT_PARSING(field = childClass.addField("isLoop", std::hash<std::string>()(std::string("c:@N@SoundSystem@S@SoundEvent@FI@isLoop") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, isLoop), &thisClass);\
field = childClass.addField("isPlayAsStart", std::hash<std::string>()(std::string("c:@N@SoundSystem@S@SoundEvent@FI@isPlayAsStart") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, isPlayAsStart), &thisClass);\
field = childClass.addField("is3D", std::hash<std::string>()(std::string("c:@N@SoundSystem@S@SoundEvent@FI@is3D") + rfk::internal::getTypename<ChildClass>()), rfk::getType<bool>(), static_cast<rfk::EFieldFlags>(1), offsetof(ChildClass, is3D), &thisClass);\
field = childClass.addField("m_soundArray", std::hash<std::string>()(std::string("c:@N@SoundSystem@S@SoundEvent@FI@m_soundArray") + rfk::internal::getTypename<ChildClass>()), rfk::getType<VectorContainer<Resources::SoundInstance>>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_soundArray), &thisClass);\
field->setPropertiesCapacity(1);\
static_assert((ResourceTypeProperty::targetEntityKind & rfk::EEntityKind::Field) != rfk::EEntityKind::Undefined, "[Refureku] ResourceTypeProperty can't be applied to a rfk::EEntityKind::Field");static ResourceTypeProperty property_4053955064475928821u_0{Resources::ResourceType::SOUND};field->addProperty(property_4053955064475928821u_0);\
field = childClass.addField("m_distanceMin", std::hash<std::string>()(std::string("c:@N@SoundSystem@S@SoundEvent@FI@m_distanceMin") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_distanceMin), &thisClass);\
field = childClass.addField("m_distanceMax", std::hash<std::string>()(std::string("c:@N@SoundSystem@S@SoundEvent@FI@m_distanceMax") + rfk::internal::getTypename<ChildClass>()), rfk::getType<float>(), static_cast<rfk::EFieldFlags>(4), offsetof(ChildClass, m_distanceMax), &thisClass);\
)\
__RFK_DISABLE_WARNING_POP \
RFK_UNPACK_IF_NOT_PARSING(rfk::internal::CodeGenerationHelpers::registerChildClass<SceneManagement::Component, ChildClass>(childClass);\
}\
\
public:  static rfk::Class const& staticGetArchetype() noexcept;\
\
)\


#define File_SoundEvent_GENERATED	\
template <> LICH_ENGINE rfk::Archetype const* rfk::getArchetype<SoundSystem::SoundEvent>() noexcept;\


