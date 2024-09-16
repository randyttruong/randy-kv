import { Controller, Get, Post } from '@nestjs/common';
import { NodeDiscoveryService } from './node_discovery.service';
import { GrpcMethod } from "@nestjs/microservices";

@Controller()
export class NodeDiscoveryController {
  constructor(private readonly nodeDiscoveryService: NodeDiscoveryService) {}

  @Get('hello')
  getHello(): string {
    return "Hello World!";
  }


  @GrpcMethod('NodeDiscoveryService', 'Test')
  getTest(): { message: string } {
    return { message: 'Test' };
  }

  @GrpcMethod('NodeDiscoveryService', 'RegisterNode')
  registerNode(): { message: string } {
    return { message: 'RegisterNode' };
  }

  @GrpcMethod('NodeDiscoveryService', 'DeregisterNode')
    deregisterNode(): { message: string } {
        return { message: 'DeregisterNode' };
    }


  // @Post('register')
  // @Post('deregister')
  // @Get('peers')
  // @Get('status/:id')
}
