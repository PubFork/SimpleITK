/*=========================================================================
*
*  Copyright Insight Software Consortium
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*         http://www.apache.org/licenses/LICENSE-2.0.txt
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*=========================================================================*/
#ifndef sitkEuler2DTransform_h
#define sitkEuler2DTransform_h

#include "sitkCommon.h"
#include "sitkTransform.h"

namespace itk
{
namespace simple
{

/** \class Euler2DTransform
 * \brief A rigid 2D transform with rotation in radians around a
 * fixed center with translation.
 *
 * \sa itk::Euler2DTransform
 */
class SITKCommon_EXPORT Euler2DTransform
  : public Transform
{
public:
  typedef Euler2DTransform Self;
  typedef Transform        Superclass;

// construct identity
  Euler2DTransform();

  explicit Euler2DTransform(const std::vector<double> &fixedCenter,
                            double angle=0.0,
                            const std::vector<double> &translation = std::vector<double>(2,0.0) );

  Euler2DTransform( const Euler2DTransform & );

  explicit Euler2DTransform( const Transform & );

  Euler2DTransform &operator=( const Euler2DTransform & );

  /** Name of this class */
  std::string GetName() const { return std::string ("Euler2DTransform"); }

/** fixed parameter */
  SITK_RETURN_SELF_TYPE_HEADER SetCenter(const std::vector<double> &params);
  std::vector<double> GetCenter( ) const;

/** parameter */
  SITK_RETURN_SELF_TYPE_HEADER SetAngle (double angle);
  double GetAngle () const;

  std::vector<double> GetTranslation( ) const;
  SITK_RETURN_SELF_TYPE_HEADER SetTranslation(const std::vector<double>& translation);

  /** additional methods */
  std::vector<double> GetMatrix() const;
  SITK_RETURN_SELF_TYPE_HEADER SetMatrix(const std::vector<double> &matrix, double tolerance = 1e-10);

protected:

  virtual void SetPimpleTransform( PimpleTransformBase *pimpleTransform );

private:

  using Superclass::AddTransform;

  void InternalInitialization(itk::TransformBase *transform);

  template <typename TransformType>
    void InternalInitialization(TransformType *transform);

  nsstd::function<void(const std::vector<double>&)> m_pfSetCenter;
  nsstd::function<std::vector<double>()> m_pfGetCenter;
  nsstd::function<void(double)> m_pfSetAngle;
  nsstd::function<double()> m_pfGetAngle;
  nsstd::function<void(const std::vector<double>&)> m_pfSetTranslation;
  nsstd::function<std::vector<double>()> m_pfGetTranslation;
  nsstd::function<std::vector<double>()> m_pfGetMatrix;
  nsstd::function<void(const std::vector<double>&, double)> m_pfSetMatrix;

};

}
}

#endif // sitkEuler2DTransform_h
