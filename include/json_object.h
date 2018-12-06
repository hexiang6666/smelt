#ifndef _JSON_OBJECT_H_
#define _JSON_OBJECT_H_

#include <iomanip>
#include <iostream>
// JSON for Modern C++ single-include header
#include <nlohmann_json/json.hpp>

namespace utilities {
// Alias for JSON type
using json = nlohmann::json;
  
/**
 * Wrapper class for JSON implementation
 */
class JsonObject {
 public:
  /**
   * Friend operator for output stream insertion
   */
  friend std::ostream& operator<<(std::ostream& out, const utilities::JsonObject& json_object);
  
  /**
   * @constructor Construct JSON wrapper
   */
  JsonObject() = default;

  /**
   * @destructor Virtual destructor
   */
  virtual ~JsonObject() {};

  /**
   * Add value to key in JSON object. If key doesn't exist,
   * it will automatically added.
   * @tparam Tparam Template parameter for value
   * @param[in] key Key to add values to
   * @param[in] value Value to add to key
   * @return Returns true if successful, false otherwise
   */
  template <typename Tparam>
  bool add_value(const std::string& key, const Tparam& value);

  /**
   * Get the value associated with the input key
   * @tparam Tparam Template parameter value
   * @param[in] key Key at which to get value
   * @return Returns value at input key. Throws exception if key is not present.
   */
  template <typename Tparam>
  Tparam get_value(const std::string& key) const;

  /**
   * Delete key from JSON object
   * @param[in] key Key to remove from JSON object
   * @return Returns true if successful, false otherwise
   */
  bool delete_key(const std::string& key);

  /**
   * Write prettified JSON object to file
   * @param[in] output_location Location to write JSON object to
   * @return Returns true if successful, false otherwise
   */
  bool write_to_file(const std::string& output_location) const;

  /**
   * Clear JSON object contents
   */
  void clear();

  /**
   * Check if JSON object is empty
   * @return Returns true if object is empty, false otherwise
   */
  bool is_empty() const;

  /**
   * Get the number of keys in the JSON object
   * @return Number of keys in the JSON object
   */
  unsigned int get_size() const;

  /**
   * Add this JsonObject as a value at the input key in the input JsonObject
   * @param[in] key Key at which to add JsonObject
   * @param[in, out] receiving_object JsonObject that this JsonObject should be added to
   */
  void add_as_value(const std::string& key, JsonObject& receiving_object) const;

 protected:
  json json_object_; /**< Json object for this class */  
};

/**
 * Overload for output stream insertion operator
 * @param[in] out Output stream to insert JSON object into
 * @param[in] json_object JSON object to insert into output stream
 * @return Reference to output stream that JSON object has been inserted into
 */
std::ostream& operator<<(std::ostream& out, const utilities::JsonObject& json_object) {
  out << std::setw(4) << json_object.json_object_;
  return out;
}; 
}  // namespace utilities

#include "json_object.tcc"

#endif  // _JSON_OBJECT_H_