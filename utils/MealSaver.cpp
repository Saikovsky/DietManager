#include "MealSaver.hpp"
#include "Logger.hpp"
#include "MealProvider.hpp"

MealSaver::MealSaver()
{
    flatbuffers::FlatBufferBuilder builder(1024);

    auto ingName = builder.CreateString("Olej");
    auto mealName = builder.CreateString("Zupa");
    auto mealDescription = builder.CreateString("asjdasjkdaksjsdkjglsdkjglsdkjglkdfjgldkfjglkdfjgldkfjg");
    auto mealType = Meals::MealType_Breakfast;
    
    auto ingredient = Meals::CreateIngredient(builder, ingName, 0.0f, 500.0f);

    std::vector<flatbuffers::Offset<Meals::Ingredient>> ingredient_vector;
    ingredient_vector.push_back(ingredient);
    
    auto ingredients = builder.CreateVector(ingredient_vector);
    
    Meals::MealBuilder meal_builder(builder);

    meal_builder.add_title(mealName);
    meal_builder.add_description(mealDescription);
    meal_builder.add_ingredients(ingredients);
    meal_builder.add_meal_type(mealType);
    auto meal = meal_builder.Finish();

    //builder.Finish(meal);
    builder.Finish(meal);

    uint8_t* buf = builder.GetBufferPointer();
    int size = builder.GetSize();
    // Get a pointer to the root object inside the buffer.
    //auto mealss = Meals::GetMeals(buf);
    
    //std::ofstream ofile("bin/data.bin", std::ios::binary);
    //ofile.write((char*)buf, size);
    //ofile.close();

    Logger log;
    //auto nameToLog = mealss->meals()->begin()->description();
    
    std::string strtolog = std::to_string((uint8_t)ok);
    log.info("nameToLog"+ strtolog);
};