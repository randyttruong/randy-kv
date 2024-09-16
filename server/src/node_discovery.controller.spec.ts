import { Test, TestingModule } from '@nestjs/testing';
import { NodeDiscoveryController } from './node_discovery.controller';
import { NodeDiscoveryService } from './node_discovery.service';

describe('NodeDiscoveryController', () => {
  let nodeDiscoveryController: NodeDiscoveryController;

  beforeEach(async () => {
    const app: TestingModule = await Test.createTestingModule({
      controllers: [NodeDiscoveryController],
      providers: [NodeDiscoveryService],
    }).compile();

    nodeDiscoveryController = app.get<NodeDiscoveryController>(NodeDiscoveryController);
  });

  describe('root', () => {
    it('should return "Hello World!"', () => {
      expect(nodeDiscoveryController.getHello()).toBe('Hello World!');
    });
  });
});
