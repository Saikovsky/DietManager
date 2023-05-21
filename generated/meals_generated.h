// automatically generated by the FlatBuffers compiler, do not modify
// Side note -> actually modified by hand to remove namespaces nested in Namespace Meals
// VS cries for fixing this as "critical error"

#ifndef FLATBUFFERS_GENERATED_MEALS_MEALS_H_
#define FLATBUFFERS_GENERATED_MEALS_MEALS_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 9,
             "Non-compatible flatbuffers version included");

namespace Meals {

struct Meal;
struct MealBuilder;

struct Ingredient;
struct IngredientBuilder;

struct Meals;
struct MealsBuilder;

enum MealType : int8_t {
  MealType_Breakfast = 0,
  MealType_secndBreakfast = 1,
  MealType_Dinner = 2,
  MealType_AfternoonSnack = 3,
  MealType_Supper = 4,
  MealType_MIN = MealType_Breakfast,
  MealType_MAX = MealType_Supper
};

inline const MealType (&EnumValuesMealType())[5] {
  static const MealType values[] = {
    MealType_Breakfast,
    MealType_secndBreakfast,
    MealType_Dinner,
    MealType_AfternoonSnack,
    MealType_Supper
  };
  return values;
}

inline const char * const *EnumNamesMealType() {
  static const char * const names[6] = {
    "Breakfast",
    "secndBreakfast",
    "Dinner",
    "AfternoonSnack",
    "Supper",
    nullptr
  };
  return names;
}

inline const char *EnumNameMealType(MealType e) {
  if (::flatbuffers::IsOutRange(e, MealType_Breakfast, MealType_Supper)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesMealType()[index];
}

struct Meal FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef MealBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MEAL_TYPE = 4,
    VT_TITLE = 6,
    VT_INGREDIENTS = 8,
    VT_DESCRIPTION = 10
  };
  MealType meal_type() const {
    return static_cast<MealType>(GetField<int8_t>(VT_MEAL_TYPE, 0));
  }
  const ::flatbuffers::String *title() const {
    return GetPointer<const ::flatbuffers::String *>(VT_TITLE);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<Ingredient>> *ingredients() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<Ingredient>> *>(VT_INGREDIENTS);
  }
  const ::flatbuffers::String *description() const {
    return GetPointer<const ::flatbuffers::String *>(VT_DESCRIPTION);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_MEAL_TYPE, 1) &&
           VerifyOffset(verifier, VT_TITLE) &&
           verifier.VerifyString(title()) &&
           VerifyOffset(verifier, VT_INGREDIENTS) &&
           verifier.VerifyVector(ingredients()) &&
           verifier.VerifyVectorOfTables(ingredients()) &&
           VerifyOffset(verifier, VT_DESCRIPTION) &&
           verifier.VerifyString(description()) &&
           verifier.EndTable();
  }
};

struct MealBuilder {
  typedef Meal Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_meal_type(MealType meal_type) {
    fbb_.AddElement<int8_t>(Meal::VT_MEAL_TYPE, static_cast<int8_t>(meal_type), 0);
  }
  void add_title(::flatbuffers::Offset<::flatbuffers::String> title) {
    fbb_.AddOffset(Meal::VT_TITLE, title);
  }
  void add_ingredients(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<Ingredient>>> ingredients) {
    fbb_.AddOffset(Meal::VT_INGREDIENTS, ingredients);
  }
  void add_description(::flatbuffers::Offset<::flatbuffers::String> description) {
    fbb_.AddOffset(Meal::VT_DESCRIPTION, description);
  }
  explicit MealBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Meal> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Meal>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Meal> CreateMeal(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    MealType meal_type = MealType_Breakfast,
    ::flatbuffers::Offset<::flatbuffers::String> title = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<Ingredient>>> ingredients = 0,
    ::flatbuffers::Offset<::flatbuffers::String> description = 0) {
  MealBuilder builder_(_fbb);
  builder_.add_description(description);
  builder_.add_ingredients(ingredients);
  builder_.add_title(title);
  builder_.add_meal_type(meal_type);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Meal> CreateMealDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    MealType meal_type = MealType_Breakfast,
    const char *title = nullptr,
    const std::vector<::flatbuffers::Offset<Ingredient>> *ingredients = nullptr,
    const char *description = nullptr) {
  auto title__ = title ? _fbb.CreateString(title) : 0;
  auto ingredients__ = ingredients ? _fbb.CreateVector<::flatbuffers::Offset<Ingredient>>(*ingredients) : 0;
  auto description__ = description ? _fbb.CreateString(description) : 0;
  return CreateMeal(
      _fbb,
      meal_type,
      title__,
      ingredients__,
      description__);
}

struct Ingredient FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef IngredientBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_WEIGHT_G = 6,
    VT_VOLUME_ML = 8
  };
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  float weight_g() const {
    return GetField<float>(VT_WEIGHT_G, 0.0f);
  }
  float volume_ml() const {
    return GetField<float>(VT_VOLUME_ML, 0.0f);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<float>(verifier, VT_WEIGHT_G, 4) &&
           VerifyField<float>(verifier, VT_VOLUME_ML, 4) &&
           verifier.EndTable();
  }
};

struct IngredientBuilder {
  typedef Ingredient Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(Ingredient::VT_NAME, name);
  }
  void add_weight_g(float weight_g) {
    fbb_.AddElement<float>(Ingredient::VT_WEIGHT_G, weight_g, 0.0f);
  }
  void add_volume_ml(float volume_ml) {
    fbb_.AddElement<float>(Ingredient::VT_VOLUME_ML, volume_ml, 0.0f);
  }
  explicit IngredientBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Ingredient> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Ingredient>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Ingredient> CreateIngredient(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    float weight_g = 0.0f,
    float volume_ml = 0.0f) {
  IngredientBuilder builder_(_fbb);
  builder_.add_volume_ml(volume_ml);
  builder_.add_weight_g(weight_g);
  builder_.add_name(name);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Ingredient> CreateIngredientDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    float weight_g = 0.0f,
    float volume_ml = 0.0f) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return CreateIngredient(
      _fbb,
      name__,
      weight_g,
      volume_ml);
}

struct Meals FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef MealsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MEALS = 4
  };
  const ::flatbuffers::Vector<::flatbuffers::Offset<Meal>> *meals() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<Meal>> *>(VT_MEALS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_MEALS) &&
           verifier.VerifyVector(meals()) &&
           verifier.VerifyVectorOfTables(meals()) &&
           verifier.EndTable();
  }
};

struct MealsBuilder {
  typedef Meals Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_meals(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<Meal>>> meals) {
    fbb_.AddOffset(Meals::VT_MEALS, meals);
  }
  explicit MealsBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Meals> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Meals>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Meals> CreateMeals(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<Meal>>> meals = 0) {
  MealsBuilder builder_(_fbb);
  builder_.add_meals(meals);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Meals> CreateMealsDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<::flatbuffers::Offset<Meal>> *meals = nullptr) {
  auto meals__ = meals ? _fbb.CreateVector<::flatbuffers::Offset<Meal>>(*meals) : 0;
  return CreateMeals(
      _fbb,
      meals__);
}

inline const Meals *GetMeals(const void *buf) {
  return ::flatbuffers::GetRoot<Meals>(buf);
}

inline const Meals *GetSizePrefixedMeals(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<Meals>(buf);
}

inline bool VerifyMealsBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Meals>(nullptr);
}

inline bool VerifySizePrefixedMealsBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Meals>(nullptr);
}

inline void FinishMealsBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Meals> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedMealsBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Meals> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Meals

#endif  // FLATBUFFERS_GENERATED_MEALS_MEALS_H_
