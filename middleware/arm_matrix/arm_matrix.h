#include "stm32f4xx_hal.h"
#ifndef float32_t
#define float32_t float
#endif

/**
 * @brief Error status returned by some functions in the library.
 */

typedef enum {
  ARM_MATH_SUCCESS = 0, /**< No error */
  ARM_MATH_ARGUMENT_ERROR = -1, /**< One or more arguments are incorrect */
  ARM_MATH_LENGTH_ERROR = -2, /**< Length of data buffer is incorrect */
  ARM_MATH_SIZE_MISMATCH = -3, /**< Size of matrices is not compatible with the operation. */
  ARM_MATH_NANINF = -4, /**< Not-a-number (NaN) or infinity is generated */
  ARM_MATH_SINGULAR = -5, /**< Generated by matrix inversion if the input matrix is singular and cannot be inverted. */
  ARM_MATH_TEST_FAILURE = -6 /**< Test Failed  */
} arm_status;

/**
 * @brief Instance structure for the floating-point matrix structure.
 */
typedef struct {
  uint16_t numRows; /**< number of rows of the matrix.     */
  uint16_t numCols; /**< number of columns of the matrix.  */
  float32_t *pData; /**< points to the data of the matrix. */
} arm_matrix_instance_f32;

/**
 * @brief Floating-point matrix addition.
 * @param[in]  pSrcA  points to the first input matrix structure
 * @param[in]  pSrcB  points to the second input matrix structure
 * @param[out] pDst   points to output matrix structure
 * @return     The function returns either
 * <code>ARM_MATH_SIZE_MISMATCH</code> or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
arm_status arm_mat_add_f32(const arm_matrix_instance_f32 * pSrcA,
                           const arm_matrix_instance_f32 * pSrcB,
                           arm_matrix_instance_f32 * pDst);

/**
 * @brief Floating-point, complex, matrix multiplication.
 * @param[in]  pSrcA  points to the first input matrix structure
 * @param[in]  pSrcB  points to the second input matrix structure
 * @param[out] pDst   points to output matrix structure
 * @return     The function returns either
 * <code>ARM_MATH_SIZE_MISMATCH</code> or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
arm_status arm_mat_cmplx_mult_f32(const arm_matrix_instance_f32 * pSrcA,
                                  const arm_matrix_instance_f32 * pSrcB,
                                  arm_matrix_instance_f32 * pDst);

/**
 * @brief Floating-point matrix transpose.
 * @param[in]  pSrc  points to the input matrix
 * @param[out] pDst  points to the output matrix
 * @return    The function returns either  <code>ARM_MATH_SIZE_MISMATCH</code>
 * or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
arm_status arm_mat_trans_f32(const arm_matrix_instance_f32 * pSrc,
                             arm_matrix_instance_f32 * pDst);

/**
 * @brief Floating-point matrix multiplication
 * @param[in]  pSrcA  points to the first input matrix structure
 * @param[in]  pSrcB  points to the second input matrix structure
 * @param[out] pDst   points to output matrix structure
 * @return     The function returns either
 * <code>ARM_MATH_SIZE_MISMATCH</code> or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
arm_status arm_mat_mult_f32(const arm_matrix_instance_f32 * pSrcA,
                            const arm_matrix_instance_f32 * pSrcB,
                            arm_matrix_instance_f32 * pDst);

/**
 * @brief Floating-point matrix subtraction
 * @param[in]  pSrcA  points to the first input matrix structure
 * @param[in]  pSrcB  points to the second input matrix structure
 * @param[out] pDst   points to output matrix structure
 * @return     The function returns either
 * <code>ARM_MATH_SIZE_MISMATCH</code> or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
arm_status arm_mat_sub_f32(const arm_matrix_instance_f32 * pSrcA,
                           const arm_matrix_instance_f32 * pSrcB,
                           arm_matrix_instance_f32 * pDst);

/**
 * @brief Floating-point matrix scaling.
 * @param[in]  pSrc   points to the input matrix
 * @param[in]  scale  scale factor
 * @param[out] pDst   points to the output matrix
 * @return     The function returns either
 * <code>ARM_MATH_SIZE_MISMATCH</code> or <code>ARM_MATH_SUCCESS</code> based on the outcome of size checking.
 */
arm_status arm_mat_scale_f32(const arm_matrix_instance_f32 * pSrc,
float32_t scale,
                             arm_matrix_instance_f32 * pDst);

/**
 * @brief Floating-point matrix inverse.
 * @param[in]  src   points to the instance of the input floating-point matrix structure.
 * @param[out] dst   points to the instance of the output floating-point matrix structure.
 * @return The function returns ARM_MATH_SIZE_MISMATCH, if the dimensions do not match.
 * If the input matrix is singular (does not have an inverse), then the algorithm terminates and returns error status ARM_MATH_SINGULAR.
 */
arm_status arm_mat_inverse_f32(const arm_matrix_instance_f32 * src,
                               arm_matrix_instance_f32 * dst);

/**
 * @brief  Floating-point matrix initialization.
 * @param[in,out] S         points to an instance of the floating-point matrix structure.
 * @param[in]     nRows     number of rows in the matrix.
 * @param[in]     nColumns  number of columns in the matrix.
 * @param[in]     pData     points to the matrix data array.
 */
void arm_mat_init_f32(arm_matrix_instance_f32 * S, uint16_t nRows,
                      uint16_t nColumns,
                      float32_t * pData);

