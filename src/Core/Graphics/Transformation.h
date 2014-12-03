#pragma once 

#include <Matrix44.h>
#include <Vector3.h>
#include <Matrix33.h>

namespace Pro {
	namespace Graphics {
		static float identity_matrix [] = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		class Transformation {
		protected:
			Matrix44<float> trans_matrix;
			Matrix33<float> x_matrix;
			Matrix33<float> y_matrix;
			Matrix33<float> z_matrix;
			Vector3<float> position;
			Vector3<float> rotation;

			// true if matrix hasn't been changed
			bool isProcessed;

		public:
			Transformation();
			~Transformation() {};

			void setRotation(const Vector3<float>& xyz);
			void setPosition(const Vector3<float>& position);
			void move(const Vector3<float>& delta);
			void rotate(const Vector3<float>& xyz);
			Matrix44<float>& getViewMatrix();
		};
	}
}