//
//  Shader.fsh
//  testXcodeGame
//
//  Created by Huabing.Xu on 9/28/14.
//  Copyright (c) 2014 Chukong. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
